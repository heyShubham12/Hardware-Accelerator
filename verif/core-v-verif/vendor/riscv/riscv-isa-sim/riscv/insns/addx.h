// ADDX: Saturating addition
// addx rd, rs1, rs2

// Perform unsigned addition
reg_t a = RS1;
reg_t b = RS2;
reg_t result = a + b;

// For RV32, mask to 32 bits
if (xlen == 32) {
  a = (uint32_t)a;
  b = (uint32_t)b;
  result = (uint32_t)result;

  // Check for signed overflow
  int32_t sa = (int32_t)a;
  int32_t sb = (int32_t)b;
  int32_t sr = (int32_t)result;

  // Both positive and result is negative -> positive overflow
  if (sa > 0 && sb > 0 && sr < 0) {
    result = 0x7FFFFFFF;  // Saturate to max positive
  }
  // Both negative and result is non-negative -> negative overflow
  else if (sa < 0 && sb < 0 && sr >= 0) {
    result = 0x80000000;  // Saturate to min negative
  }
} else {
  // For RV64
  int64_t sa = (int64_t)a;
  int64_t sb = (int64_t)b;
  int64_t sr = (int64_t)result;

  // Both positive and result is negative -> positive overflow
  if (sa > 0 && sb > 0 && sr < 0) {
    result = 0x7FFFFFFFFFFFFFFFULL;  // Saturate to max positive
  }
  // Both negative and result is non-negative -> negative overflow
  else if (sa < 0 && sb < 0 && sr >= 0) {
    result = 0x8000000000000000ULL;  // Saturate to min negative
  }
}

WRITE_RD(sext_xlen(result));
