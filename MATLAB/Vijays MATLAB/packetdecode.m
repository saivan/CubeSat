function [pictures]=packetdecode(totalframes,frames,pictures)

D=size(frames);

for i=1:D(2)
    framechar=char(frames(i));
    
    destinations=cellstr(framechar(2:7));
    datatype=cellstr(framechar(8));
    sources=cellstr(framechar(9:14));
    control=cellstr(framechar(16));
    pid=cellstr(framechar(17));
    
    infolength=length(framechar)-20;
    information=framechar(18:17+infolength);
    
    if(char(datatype)=='`')
        %WOD decode
    else
        pictures=[pictures information];
    end
end

totalframes=totalframes+D(2);
pictures

% %%%%% Check FCS (CRC) value                           %%%%%%
% FCS=cellstr(char(packet((packetlength-2):(packetlength-1))));
%     
% %%%%% Interpret data field appropriately              %%%%%%
%    
%     if(char(datatype)=='`')
%         %%%%% Calls WODdecode.m                               %%%%%%     
%         [Time,WOD]=WODdecode(information);
%         xlswrite('Downlink_Log.xlsx',WOD,2,'A3:H100');
%         xlswrite('Downlink_Log.xlsx',Time,2,'B1:B4');
%     elseif(char(datatype)=='p')
%         % Add elseif for science type data 
%     end   
% 
% newframe=[destinations datatype sources control pid information FCS];

end