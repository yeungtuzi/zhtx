var ComputerObj = GetObject("WinNT://edu-sp/liufeng_MUDOS_EXE",service);
var service = ComputerObj;
//    WScript.Echo "Service display name = " & Service.DisplayName
//    WScript.Echo "Service executable   = " & Service.Path
//    WScript.Echo "Current status       = " & Service.Status

while(1)
{
	if(service.status != 4)
	{
		service.stop();
		wscript.sleep(60000);
		service.start();
		wscript.sleep(1800000);
	}
}

