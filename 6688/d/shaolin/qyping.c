// Room: /d/shaolin/qyping.c

inherit ROOM;

void create()
{
        set("short", "青云坪");
        set("long", @LONG
这里便是少室绝顶。极目望去，只见白云缕缕，如苍龙绕岭；
嵩山拔翠，似金刚擎天。山腰五道瀑布飞泻而下，石级蜿延曲折，
宛若一条长虫，游人纷纷其上，已如蚁蛭。面前的平地上寸草不
生，正中三棵巨松围成一圈，圈中央似乎有什么东西在闪闪发光。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"shulin"+(random(2)+15),
 //               "enter" : __DIR__"fumoquan",
        ]));

        set("outdoors", "shaolin");
        setup();
}
void init()
{
             add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="fumoquan"||arg=="伏魔圈" ) 
        {
              object * inv;
             int i;
                inv = all_inventory(me);
                for( i=0;i<sizeof(inv);i++) 
                {
                        if( inv[i]->is_character() )
                                return notify_fail("你不能背着"+inv[i]->query("name")+"进去!\n");
                 }
 
       if ( present("fumo dao", me) || present("jingang zhao", me)
          || present("fumo dao", environment(me)) || present("jingang zhao", environment(me)) )
                return notify_fail("只听里面有人说道: 大侠上回已来过此处，此刻身携重宝，不便进入，\n恕老衲等失礼了。\n");
        if ( me->query("kee") > me->query("max_kee") )
                return notify_fail("你想用ｂｕｇ牟利，呵呵！\n");
                {
                 message("vision",
                        me->name() + "运足全身劲力,向金刚伏魔圈中纵身一跃。\n",
                        environment(me), ({me}) );
                me->move(__DIR__"fumoquan");
                message("vision","只见"+
                        me->name() + "左闪右躲,极力往伏魔圈中间跃来。\n",
                        environment(me), ({me}) );
                return 1;
                  }
        }
}       
