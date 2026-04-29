// Room: cemen.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIM"侧门"NOR);
	set("long", @LONG
皇宫的一个小小的侧门。方便平时太监出入购物办事。现在一个老太监
正坐在一张桌子后边，手中拿着一个记录本和毛笔，正在登记着什么，桌子
前靠着一个小牌子(sign)。不知道这是怎么回事。
LONG
	);

	set("item_desc", ([
		"sign" : (:look_gaoshi:),
	]));

	set("exits", ([
		"east" : __DIR__"zijincheng",
		"north" : __DIR__"zoulang1",
		"west"  :__DIR__"fang3",
	]));
        set("objects", ([
                __DIR__"npc/old_taijian" : 1,
                __DIR__"npc/wander" : 2,
                __DIR__"npc/shiwei" : 1,
		__DIR__"npc/wujiang":1,
        ]));
	set("outdoors", "bj");
	create_door("west", "小门", "east", DOOR_CLOSED);
	setup();
}

string look_gaoshi()
{
	return "\n宫中急招一批年龄在15至20岁之间的强壮青年做太监，\n"
         "月俸一两银子。有意者请从速应召(apply)。\n";
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
	if(present("taijian fu",me))
	return ::valid_leave(me,dir);
if(dir=="north")
 {
     if( this_player()->query("huanggong/canenter") )
        {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop")&& (inv[i]->query("equipped")))
		if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
                    return notify_fail("武将上前挡住你，朗声说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。\n"
                        "不得持兵刃入宫。\n");
                else if(objectp(present("guan bing", environment(me)))&&living(present("bing", environment(me))))
                    return notify_fail("官兵上前挡住你，朗声说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。\n"
                        "不得持兵刃入宫。\n");
	return ::valid_leave(me, dir);
        }
     else
     {
     if (me->query("gender") == "女性") {
        if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
            return notify_fail("武将上前挡住你,朗声说道：皇宫重地，岂" 
            "容寻常烟花女子自由出入,\n" + RANK_D->query_respect(me) +"请回，免得"
                "自取其辱。\n");
        else if(objectp(present("guan bing", environment(me))))
            return notify_fail("官兵上前拦住你，朗声说道：皇宫重地，岂" 
            "容寻常烟花女子自由出入,\n" + RANK_D->query_respect(me) +"请回，免得"
            "自取其辱。\n");
    	}
     if (me->query("gender") == "无性") {
        if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
            say("武将笑吟吟地说道：这位公公您辛苦了，快请进吧。\n");
        else if(objectp(present("guan bing", environment(me)))&&living(present("bing", environment(me))))
            say("官兵笑吟吟地说道：这位公公您辛苦了，快请进吧。\n");
    	}
     if (me->query("gender") == "男性") {
        if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
            return notify_fail("武将伸手拦住你朗声说道：皇宫重地，岂" 
            "容寻常乡村野夫自由出入.\n" + RANK_D->query_respect(me) +"请回，免得"
                "自取其辱。\n");
        else if(objectp(present("guan bing", environment(me)))&&living(present("bing", environment(me))))
            return notify_fail("官兵伸手拦住你朗声说道：皇宫重地，岂" 
            "容寻常乡村野夫自由出入\n" + RANK_D->query_respect(me) +"请回，免得"
            "自取其辱。\n");
    	}
      }
}	
return ::valid_leave(me, dir);
}

