module Counter8(
    clk, rst, out

    );
    input clk; // ����ʱ��
    input rst;//��λ
    output reg [2:0]  out; // ����ֵ
         
    always @(posedge clk or posedge rst)  
    if (rst)
        out <= 3'b000;
    else  // ��ʱ�������ؼ�������1
          out <= out + 1;                               
endmodule
