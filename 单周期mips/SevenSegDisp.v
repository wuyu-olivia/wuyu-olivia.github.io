module SevenSegDisp(clk, SW, data, SEG, AN);
    input clk;       //ʱ��
    input [15:0] SW;       // 16λ��������
    input [31:0] data;     //����ʾ����
    output [7:0] SEG;      // 7��������������͵�ƽ��Ч
    output [7:0] AN;       // 7�������Ƭѡ�źţ��͵�ƽ��Ч
   
    //wire [31:0] data;
    wire [2:0] sel;
    wire [3:0] bcd;
    wire clk;
    assign rst = SW[0];
    //assign data = {16'h8765, SW[15:0]};

    Select U_SLCT(sel, data, bcd);
    SevenSegDecoder U_SSD(bcd, SEG);
    Counter8 U_CNT(clk, rst, sel);   
    Decoder3_8 U_D38(sel, AN);
endmodule
