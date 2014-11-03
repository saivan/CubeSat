rangestring = ['B', num2str(totalframes+i+2),':F', ...
num2str(totalframes+i+2)];
xlswrite('Downlink_Log.xlsx',class,1, rangestring);
totalframes=totalframes+D(2);