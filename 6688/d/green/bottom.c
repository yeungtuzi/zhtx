
inherit ROOM;

void create()
{
        set("short", "潭底");
        set("long", @LONG
这里实在很美，很静。泉水清澈冰凉，各式各样的鱼虾在你的面前悠
闲的游来游去，看著水草在砂石间娥娜起舞，这种感觉不是未曾经历此境
的人所能领略得到的。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"bottom1",
  ]));
        set("objects", ([
        __DIR__"npc/fish" : 1,
        __DIR__"npc/shrimp" : 1,
                        ]) );

        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i,weight;
         weight=0;
        if( userp(me)) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                       weight=weight+inv[i]->query_weight();
                        }
                   if (weight>40000) return notify_fail("\n你身子只往下坠，怎么也游不上去！\n");
              
                       }  
        me->set_temp("got-yu",1);
        return 1;
}


