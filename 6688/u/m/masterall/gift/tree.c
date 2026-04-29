inherit ITEM;
#include <ansi.h>

void init()
{
  add_action("do_climb", "tiao");
  add_action("do_pick", "pick");
}

void create()
{
        set_name(HIG"圣诞树"NOR, ({"Christmas tree ", "tree"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", HIY"这是一颗装饰得极为华丽的圣诞树，每个玩家都可以从上面摘取（pick）一件礼物。\n但不知天神道全从哪里搞来这么大一棵树，高得你都看不到树尖。\n如果你轻功足够好，可以试着跳上去（tiao）,看看上面是不是有更好的礼物。\n"NOR);
               set("unit", "颗");
               set("material", "wood");
               set("no_get", HIR"也不看看这是什么东西，是你随随便便就能搬回自己家的吗？\n"NOR);
               set("no_give",1);
               set("no_drop", 1);
               set("no_put", 1);
               set("no_sell", 1);
               set("no_paimai", 1);
               set("unpawnable", 1);

        }
        setup();
}

int do_climb(string arg)
{
        object me = this_player();
        int skill;
        skill = me->query_skill("dodge", 1);
        if ( !arg || arg !="tree")
                return notify_fail("你要往哪儿跳？\n");
        if (me->query("dummy") )
                return notify_fail("圣诞礼物不给大米！！\n");
        if ( skill <= 200 ) 
        {
                write("你的轻功等级太低了，别试了，累死你也跳不上去的。\n");
                return 1;
        }
        else if ( skill > 200 && skill <= 250)
        {
                message_vision(YEL"$N双足运力，飞身一纵，不待向下坠落，已然伸手扒住了下面的圣诞树的下面的大树杈。\n"NOR, me);         
                me->set_temp("tree1", 1);
                me->move("/u/m/masterall/gift/tree1.c");
                return 1;
        }
        else if ( skill > 200 && skill <= 300)
        {
                message_vision(HIY"$N运足真气，身子如孤雁般飞起，未等去势衰老，已稳稳地落在中间的树杈上。\n"NOR, me);         
                me->set_temp("tree2", 1);
                me->move("/u/m/masterall/gift/tree2.c");
                return 1;
        }
        else if ( skill > 300 && skill <= 399)
        {
                message_vision(HIG"$N体内的真气不断的凝聚，一道强烈的气劲顿时迸发出来，身子如利箭般激射而出，\n四周人惊呼之余，$N已纵到了极高的树梢上。\n"NOR, me);         
                me->set_temp("tree3", 1);
                me->move("/u/m/masterall/gift/tree3.c");
                return 1;
        }
        else
        {
                message_vision(HIC"$N微微一笑，身形似乎动了一动，待等旁人四下找寻之时，却惊愕的发现$N已飞到了几乎入云的树尖上！\n"NOR, me);         
                me->set_temp("tree4", 1);
                me->move("/u/m/masterall/gift/tree4.c");
                return 1;
        }
}

int do_pick(string arg)
{
        object me = this_player();
        object ob = new("/u/m/masterall/gift/norgift.c");

//        if (arg!="gift")
//                return notify_fail("你摘什么？\n");
        if ( me->query("chgift_got") ) 
        {
                write(HIR"每个人只能拿一个礼物，你怎么这么贪心！给你找个地方闭门思过吧！\n"NOR);
                me->move("/d/wizard/prizon.c");
                return 1;
        }
        else 
        {
                message_vision(HIM"$N满心欢喜的从圣诞树上摘下一件礼物。\n"NOR, me);         
                me->set("chgift_got", 1);
                ob->move(me);
                ob->set("owner", me);
                return 1;
        }
}


