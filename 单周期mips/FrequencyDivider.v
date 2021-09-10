module FrequencyDivider (clk, clk1000Hz, clk100Hz, clk10Hz, clk1Hz);//��Ƶ��
    input  clk;              // ϵͳʱ��
    output reg  clk1000Hz;  // ��Ƶ���ʱ��1000Hz
    output reg  clk100Hz;   //��Ƶ���ʱ��100Hz
    output reg  clk10Hz;    //��Ƶ���ʱ��10Hz
    output reg  clk1Hz;     // ��Ƶ���ʱ��1Hz
    parameter      N1000 = 50_000;          // 1000Hz��ʱ��,N=fclk/fclk_N
    parameter      N100 = 50_000_0;          // 1000Hz��ʱ��,N=fclk/fclk_N
    parameter      N10 = 50_000_00;          // 1000Hz��ʱ��,N=fclk/fclk_N
    parameter      N1 = 50_000_000;         // 1Hz��ʱ��,N=fclk/fclk_N
    reg [31:0]      counter1000, counter100, counter10, counter1;  /* ������������ͨ������ʵ�ַ�Ƶ��
                                                ����������0������(N/2-1)ʱ��
                                                ���ʱ�ӷ�ת������������ */
    always @(posedge clk)  begin              // ʱ��������
        if(counter1000==N1000) begin
            clk1000Hz <= ~clk1000Hz;
            counter1000 <= 32'h0;
        end            
        else 
            counter1000 <= counter1000 + 1;
    end
    
    always @(posedge clk)  begin              // ʱ��������
        if(counter100==N100) begin
            clk100Hz <= ~clk100Hz;
            counter100 <= 32'h0;
        end            
        else 
            counter100 <= counter100 + 1;
    end
    
    always @(posedge clk)  begin              // ʱ��������
        if(counter10==N10) begin
            clk10Hz <= ~clk10Hz;
            counter10 <= 32'h0;
        end            
        else 
            counter10 <= counter10 + 1;
    end
    
    always @(posedge clk)  begin              // ʱ��������
        if(counter1==N1) begin
            clk1Hz <= ~clk1Hz;
            counter1 <= 32'h0;
        end            
        else 
            counter1 <= counter1 + 1;
    end
endmodule