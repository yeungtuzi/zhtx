//write by lysh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "悬崖边");
        set("long", @LONG
    四面古木苍松，只有风吹松涛，幽韵天成，仰视苍天，注视群山
令人不觉怆然， 云，翻腾在脚下，象海浪，又象流水。往下眺望，似乎
有波光粼粼。
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"shanlu2",
]));
        set("outdoors", "jitang");

        setup();

}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_climb","climb");
}

int do_jump()
{
        object me=this_player();
        object *inv;
        int i,weight;
        if ((int)me->query_skill("dodge")<100)
        write("你疯了，想找死呀！！！\n");
        else
        {
         if (!me->query_temp("get-yu")) {write("你疯了，想找死呀！！！\n");
                                         return 1;
					}
          message("vision",
                CYN "你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n\n"
                NOR     "不知道什麽时候，你发现自己飘在水中，四周的景物让你惊讶不已。\n\n", me);
        
         weight=0;
        if( userp(me)) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)  weight=weight+inv[i]->query_weight();
                  
                       } 
          if (weight>40000) me->move(__DIR__"bottom");
          else me->move(__DIR__"bottom1");

        }
        return 1;

}
int do_climb()
{       object me=this_player();
	message_vision(HIY "\n$N小心翼翼地向下爬去，身形慢慢被默认云雾中。\n" NOR, me);
        message_vision(HIY "\n$N到了山谷底。\n" NOR,me);                                
        me->move(__DIR__"xuanyadi");
       return 1;
}       