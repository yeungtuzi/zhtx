// /obj/toy/mainboard.c

//inherit ITEM;

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;


void create()
{
        set_name("主板", ({ "mainboard", "mother board", "board" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
     set("long","这是一块电脑主机板,也叫母板,是安装其它零件的基础,它也是\n" +
                "主板教徒的圣物,在必要的时候教徒要跪(kneel)在上面.\n");
        set("value", 50000);
                set("wield_msg", "$N抓起一块$n,握在手中当武器。\n");
                set("unwield_msg", "$N将手中的$n夹在胳膊下。\n");
        set("material", "iron");
        }
        init_hammer(2);
        setup();
}

void init()
{
        add_action("do_kneel", "kneel");
}

int do_kneel(string arg)
{
        string me, what, wifename;
        object who, ob, wifeob;
        int temp;

        if (!arg) arg = "board";
        if (interactive(who=this_player())) {
        if (who->query("gender") != "男性")
          return notify_fail("你犯不上对人这么卑躬屈膝.\n");
        if (!objectp(ob=present("marrycard",who))) 
          return notify_fail("你还在光协里,不必受这份儿罪了.\n");
        what=ob->query("name");
        if ( sscanf(what,"你和%s的婚约" ,wifename)!=1 )
                return notify_fail("你没有伴侣.\n");
        wifeob = find_player(wifename);
        if( !wifeob ) 
          return notify_fail("你老婆没上线,你现在怎么表现也没有用.\n");
        if (arg != "board")
          return notify_fail("你要在哪里下跪??!!\n");

message_vision(MAG "$N拿起一块主机板,扑通一声跪了下去!\n" GRN, who);
message_vision("$N痛哭流涕地对$n说:好老婆,我错了,原谅我吧!\n", who, wifeob);
message_vision("$N大叫:好老婆!你不原谅我我可不起来啦!\n" NOR, who);

          who->start_busy(7);
          temp = who->query("kee");
          temp -= 80;
          if ( temp <= 1 ) temp =1;
          who->set("kee", temp);
        return 1;
        }
        return 1;
}

