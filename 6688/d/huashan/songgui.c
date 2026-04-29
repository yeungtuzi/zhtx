//songgui.c 松桧
//by emote

inherit ROOM;

void create()
{
	set("short","金天宫");
	set("long",
@LONG
这里是华山南峰的两大主峰之一，山顶上长满了松树和桧树，显的环境很
是清幽，也有点阴森森的。周围一个人也没有，你不由感到心中一股寒意涌了
上来。

LONG);
         set("exits", ([ /* sizeof() == 2 */
		"eastdown"  : __DIR__"jintian",
		]));
	 
	set("outdoors","huashan");
	setup();
	
}
