// Room: /d/tangmen/keting.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "客厅");
        	set("long", @LONG
       这里是唐门门主会客的客厅。在客厅正面挂着一幅对联，
上联写着“莫以善小而不为”，下联写着“莫以恶小而为之”，
横联是“人当自省”。厅中有一些桌椅，茶几之类的摆设，唐
云正与夫人在喝茶聊天。
LONG
        		);
	set("valid_startroom",1);
        	set("exits", ([ /* sizeof() == 1*/
  		"south"  : __DIR__"guodao",  
		]));
	set("objects",([
		CLASS_D("tangmen")+"/tangyun"  : 1,
                CLASS_D("tangmen")+"/press"  : 1,
		CLASS_D("tangmen")+"/fangrou"        : 1,
		]));

        	setup();
        	replace_program(ROOM);
}

