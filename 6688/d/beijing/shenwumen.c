// Room: /u/p/pock/bj/shenwumen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"神武门"NOR);
	set("long", @LONG
神武门是皇宫的后门，虽然是后门，但毕竟也是皇宫的一个大出口。
这里的防范是丝毫不逊色于前门的。高大的围墙把民间和皇宫两个截然不
同的世界分割开来。门前侍卫正认真地在执勤，谁也不敢偷懒，这可是掉
脑袋的大事啊。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"pingfeng",
		"west" : __DIR__"beihai1",
	]));
        set("objects", ([
                __DIR__"npc/shiwei" : 2,
                __DIR__"npc/wujiang" : 2,
                __DIR__"npc/bing" : 2,
        ]));
	set("outdoors", "bj");
	setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object *inv;
        if(dir=="south")
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
           if(me->query("gender") == "女性") 
	    {
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
        if(objectp(present("wu jiang", environment(me))))
           return notify_fail("武将双手一拦，说道：这位公公，请走南边侧门。\n");
        else if(objectp(present("guan bing", environment(me))))
            return notify_fail("官兵双手一拦，说道：这位公公，请走南边侧门。\n");
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
