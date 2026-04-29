// Room: /d/tangmen/wzoulang1.c         
//writen by tang

inherit ROOM;

void create()
{
        set("short", "西走廊");
        set("long", @LONG
这里是西走廊，两边房子里都颇为安静。北面是男弟子休息室，南面是
是女弟子休息室。
LONG
        		);
        set("exits", ([ /* sizeof() == 4*/
	  	"east"   : __DIR__"guodao",  
		"west"  : __DIR__"wzoulang2",
		"north"  : __DIR__"mbedroom",
		"south" : __DIR__"wbedroom",
		]));
	set("objects",([
		__DIR__"npc/dizi3"  : 1
		]));
        set("outdoors", "tangmen");

        setup();

}

int valid_leave(object me, string dir)
{
	if( me->query("family/family_name") != "唐门"
		&& (dir == "south" || dir == "north") )
		return notify_fail("你非唐门弟子，不能进去。\n");
	if( me ->query("gender")=="男性" && dir=="south")
	   	return notify_fail("你是男弟子，不要进女弟子休息室。\n");
	if( me ->query("gender")=="女性" && dir=="north")
	   	return notify_fail("你是女弟子，不要进男弟子休息室。\n");
	return ::valid_leave(me, dir);
}
