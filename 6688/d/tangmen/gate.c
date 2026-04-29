// Room: /d/tangmen/gate.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "大门");
        	set("long", @LONG
这就是著名的蜀中唐门，乃江湖四大世家之一。大门两旁有两个
巨大的石狮子，一百三十八级台阶，每级都有一尺多高，普通人
上下很费劲，也不知道有什么用。有一个唐门六代弟子站在门前，
正上下打量着你。
LONG
        		);
        	set("exits", ([ /* sizeof() == 2 */
  		"north"  : __DIR__"qianyuan",
  		"south"  : __DIR__"road2",
		]));
	set("objects",([
                __DIR__"npc/dizi3"  : 1,
                "/class/tangmen/tangque"  : 1,
		]));
        	set("outdoors", "tangmen");

        	setup();
        	replace_program(ROOM);
}

