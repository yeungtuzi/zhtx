// Room: zijincheng.c
#include <ansi.h>


inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIM"紫禁城"NOR);
	set("long", @LONG
这便是皇宫正门。巍峨雄伟的城墙上，'紫禁城'三个大字十分显眼，气势
辉煌。一张镶金边的告示(gaoshi)贴在墙上，许多官兵立在两旁。
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"south" : __DIR__"bridge1",
		"north" : __DIR__"qihedian",
		"west"  :__DIR__"cemen",
	]));
        set("objects", ([
                __DIR__"npc/shiwei" : 2,
                __DIR__"npc/wujiang" : 2,
                __DIR__"npc/bing" : 2,
        ]));
	set("outdoors", "bj");
	setup();
}

string look_gaoshi()
{
	return "\n辑拿天地会一众反贼! \n举报一人，赏金十两;\n"
          "捉拿一人，赏金百两。\n知情不报者，立斩!\n鳌拜发\n";
}

int valid_leave(object me, string dir)
{
        int i;
        object *inv;
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
           return notify_fail("武将双手一拦，说道：这位公公，请走侧门。\n");
        else if(objectp(present("guan bing", environment(me))))
            return notify_fail("官兵双手一拦，说道：这位公公，请走侧门。\n");
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

