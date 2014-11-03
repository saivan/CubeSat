Mode=input('Enter satellite mode (0-5): ');

Flag=126;

Destination=[71 65 77 83 65 84];
Address=[170 166 178 136 96 98]/2;
SSID=85;

Control=42;
PID=120;

Info=48+Mode;

[FCS] = [mean(Info) mean(Info)];

command=[Flag Destination SSID Address SSID Control PID Info ...
    FCS Flag];
disp('AX.25 Command is: ');
disp(char(command));
disp('Non-Shifted Decimal Representation is: ');

%%%%% No character shift while sending! %%%%%

fprintf(1,'%0.0f\n',command);