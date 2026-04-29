//ROOM:/d/suzhou/liushui.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

void create()
{                           
	set("short", YEL"急流水"NOR);
	set("long", @LONG
        	 你在急流中挣扎，不时呛进一口水。
LONG
	);                                        
  	setup();   
}              

