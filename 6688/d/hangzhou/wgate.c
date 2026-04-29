//ROOM: d/hangzhou/wgate.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

void create()
{
	set("short", MAG"西城门"NOR);
	set("long", @LONG
	  这是素来有天堂之称的杭州的西城门，城门正上方写有“西门”两个大字，
官兵们戒备森严。一条笔直的青石板大道向东西两边。西边是有名的浣纱亭，远处有
些景色迷人，游人如织，东边是城里。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"hsting",
		"east" : __DIR__"gchang",
]));  

	set("objects", ([
		 "/obj/npc/bing" : 3,
		 "/obj/npc/wujiang1"+random(3) : 1,
]));
	setup();
}   
    

void init()
{
        object me,guanchai;

        me = this_player();

        if( interactive(me) && me->query("pk_exp") > 0 && !me->query_temp("be_ki
lled"))
        {
        message_vision(HIR "突然间斜刺里冲出一个官差！\n\n" NOR, this_player());
        guanchai=new("/d/city/npc/guanchai");
        guanchai->move("/d/city/dongmen");
        write(RED"官差大喝道：你欺凌弱小，拿命来！\n"NOR);
        }


}

int valid_leave(object me, string dir)
{

        if( me->query("pk_exp") > 0 )
        {
                return notify_fail("你还没有对付官差，怎么离开这里？\n");
        }
        return ::valid_leave(me, dir);
}







