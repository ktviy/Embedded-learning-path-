// Computes R0 * R1 and stores result in R2

    // R2 = 0
    @R2
    M=0

    // Sei i = R1
    @R1
    D=M
    @i
    M=D // D=i

(LOOP)
    // if counter == 0 goto END
    @i
    D=M
    @END
    D;JEQ

    // R2 = R2 + R0
    @R0
    D=M 
    @R2
    M=D+M

    // i--
    @i
    M=M-1

    @LOOP
    0;JMP

(END)
    @END
    0;JMP

