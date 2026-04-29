#include <ansi.h>
#include <armor.h>

inherit NECK;

string *start_room = ({
        "/d/snow/inn",
        "/d/jingcheng/tamgch",
        "/d/mingjiao/dadian",
//      "/d/guanwai/chanhouse",
        "/d/latemoon/latemoon1",
        "/d/shaolin/guangchang2",
        "/d/suzhou/shizx",
        "/d/canyon/camp1",
        "/d/heimuya/cdd",
        "/d/xueshan/house",
        "/d/taohua/houhuayuan",
        "/d/oldpine/clearing",
//      "/d/resort/bamboo_hall",
        "/d/xanadu/hall",
        "/d/yueyang/guangchang",
        "/d/tieflag/goldroom",
        "/d/mingjiao/shangyueting",
        "/d/emei/dadian",
        "/d/death/gate",
        "/d/tieflag/stone1",
        });

void create()
{
     set_name(HIC "月光宝盒" NOR, ({"moon casket","casket"}) );
     set_weight(50);
     set("no_sell",1);
     set("unpawnable",1);
     set("no_drop",1);
     set("no_give",1);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", HIC"一个精致无比的小匣子，发出淡淡的青色光芒，它能让你在时空中穿梭。\n"
                        "使用方法： stay 能让你记住此地，pray back能让你回到此地，pray start\n会让"
                        "你在时空中自由穿梭。\n"NOR);
            set("unit", "只");
            set("value", 0);
            set("armor_prop/spells",100);
            set("armor_prop/dodge", 20);
            set("armor_prop/attack", 20);
            set("wear_msg", "$N把$n的带子解开，挂在自己的颈中。\n");
     }
     setup();
     if( clonep() )
             call_out("destroy",1800); //产生1个小时后自动消失。
}

void init()
{
            add_action("do_pray","pray");
            add_action("do_stay","stay");
}

int do_stay(string arg)
{
        set("start_room",base_name(environment(this_player())));
        write("OK.\n");
        return 1;
}

int do_pray(string arg)
{
        string name,my_name;
        string home;

        if( this_player()->is_busy() )
                                return notify_fail("你正忙着呢。\n");

                       if( this_player()->is_fighting() )
                                     return notify_fail("战斗中还能分神祈祷？呵呵。\n");


        name = (string)this_player()->query("name");
        my_name = query("name");

        if( !arg || (arg!="start" && arg!="back") ) return notify_fail("你要祈求什麽? \n");
        {
                message_vision("\n$N双手轻轻摩挲"+my_name+"光洁的表面，"+my_name+"淡青色的光芒不住流动。\n"
                HIR"突然一阵时空扭曲...\n\n"NOR,this_player() );
                this_player()->receive_damage("sen",20);
                if( arg =="start" || !query("start_room") )
                        home = start_room[random(sizeof(start_room))];
                else
                        home = query("start_room");
                tell_room(environment(this_player()),
                        GRN"原先"+name+"所立的地方已空无一物。\n"NOR,this_player() );
                tell_room(home,
                        GRN"突然这里一阵时空扭曲，"+name+"的身影似乎刚刚出现，又似乎早已在此。\n"NOR,this_player() );
                this_player()->move(home);
          }
          return 1;
}

void destroy()
{
//      message_vision(query("name")+"发出若隐若现的金色光芒，突然之间金光大盛，光芒消失后，"+query("name")+"也一起消失了。\n",environment());
        destruct(this_object());
}

