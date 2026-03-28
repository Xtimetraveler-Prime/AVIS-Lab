`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/24/2026 10:06:06 PM
// Design Name: 
// Module Name: tb_snn_infer_axi
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

//import axi_vip::*;
// This package name matches your VIP instance name (likely axi_vip_0)
import axi_vip_0::*;

module tb_snn_infer_axi;


// clock/reset
  logic aclk = 0;
  logic reset = 0;
  always #5 aclk = ~aclk; // 100 MHz

  // DUT = your bd wrapper (name depends on what Vivado created)
  design_1_wrapper dut (
    .aclk(aclk),
    .reset(reset)
  );

  // AXI VIP master agent type (from axi_vip_0_pkg)
  //axi_vip_0_mst_t mst;

  // Helpers: float <-> u32
  function automatic logic [31:0] f2u(input shortreal f);
    f2u = $shortrealtobits(f);
  endfunction

  function automatic shortreal u2f(input logic [31:0] u);
    u2f = $bitstoshortreal(u);
  endfunction

  // Register offsets from xsnn_infer_hw.h
  localparam int AP_CTRL   = 'h00;
  localparam int STATE0    = 'h10;
  localparam int STATE1    = 'h18;
  localparam int STATE2    = 'h20;
  localparam int ACTION    = 'h28;
  localparam int ACTION_V  = 'h2C;
  localparam int LOGPROB   = 'h38;
  localparam int LOGPROB_V = 'h3C;

  task automatic run_vec(input shortreal s0, s1, s2);
    logic [31:0] r, a_bits, lp_bits, vld;

    // write inputs
    axi_write(STATE0, f2u(s0));
    axi_write(STATE1, f2u(s1));
    axi_write(STATE2, f2u(s2));

    // start
    axi_write(AP_CTRL, 32'h0000_0001);

    // wait for done (bit1) OR output valid bits
    do begin
      axi_read(AP_CTRL, r);
    end while ((r[1] == 1'b0));

    // read outputs
    axi_read(ACTION, a_bits);
    axi_read(LOGPROB, lp_bits);

    // (optional) check valid flags (bit0 = *_ap_vld, clear-on-read)
    //axi_read(ACTION_V, vld);
    //axi_read(LOGPROB_V, vld);

    $display("state=(%f,%f,%f) => action=%f log_prob=%f",
             s0, s1, s2, u2f(a_bits), u2f(lp_bits));
  endtask

  initial begin
    // reset
    reset = 0;
    repeat (10) @(posedge aclk);
    reset = 1;
    repeat (5) @(posedge aclk);

    // IMPORTANT: bind VIP master agent to the VIP instance interface
    // You must set this path correctly (see instructions below).
//    mst = new("mst", dut.bd_ip_sim_i.axi_vip_0.inst.IF);
//    mst.start_master();

    // run a few test vectors
    run_vec(0.0, 0.0, 0.0);
    run_vec(1.0, 0.0, -1.0);
    run_vec(0.2, -0.5, 0.7);

    $finish;
end
   
endmodule
