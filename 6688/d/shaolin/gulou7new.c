// Room: /d/shaolin/gulou7.c
// Date: YZC 96/01/19

inherit ROOM;
#include <ansi.h>


string look_drum();
string look_out();


void create()
{
        set("short", "鼓楼七层");
        set("long", @LONG
这里就是鼓楼之顶。直入眼帘的便是一只大鼓。大鼓鼓身通红，
似由白杨木箍成。两头包以水牛皮，用一匝大铜钉钉在鼓身边缘。
鼓心有一圈白渍，看来是因为多次击打形成的。整个大鼓放在一
个一人高的架子上，架子底层搁着两根大鼓槌。尽管山风吹人欲
倒，谁都禁不住想击一下鼓(drum)试试。往外看，有个很大的汉
白玉窗台(out)，上面足可站一个人。
LONG
        );

        set("exits", ([
                "down" : __DIR__"gulou6",
        ]));

        set("item_desc",([
                "drum"          :       (: look_drum :),
                "out"           :       (: look_out :),
        ]));
        set("objects",([
                CLASS_D("shaolin") + "/qing-wen" : 1,
        ]));
        setup();
}


void init()
{
        add_action("do_hit", "hit");
        add_action("do_out", "out");
}

int do_hit(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "drum" ) ) return notify_fail("你要敲什麽？\n");

        me->add("kee", -30);

        if ( random((int)me->query("kar")) < 5 )
        {
                message_vision("$N一不小心敲到自己头上了。\n", me);
                //me->add("kee", -10 - me->query("qi"));
                me->unconcious();
        }

        else
        {
                mapping mine;

                mine = me->query_entire_dbase();
                message_vision("$N敲了一下大鼓，『咚……』声音传遍整个寺庙。\n", me);
                write("鼓声如迅雷般在你耳边炸响，你头脑中一片糊涂，\n"
                        "全身摇摇欲坠，勉力支撑着不倒在地上。心中一个\n"
                        "声音告诉你，得赶快离开这里，不然就没命了。\n");
//              if ( mine["potential"] - mine["learned_points"] < 100 )
//                      mine["potential"] += 0;
        }
        return 1;
}

int do_out(string arg)
{
        object me;


        int i, ging_cost, qi_cost;

        me = this_player();
        i = (int)me->query_skill("dodge", 1);

        if(me->query("force")< 20)
                return notify_fail("你的内力好像不太充沛，还是别跳了，怪吓人的。\n");

        if(me->query("gin")< 20)
                return notify_fail("你的精力好像不太够，还是别跳了，怪吓人的。\n");

        if(me->query("sen")< 20)
                return notify_fail("你的神好像不太够，还是别跳了，怪吓人的。\n");

        message_vision(HIC"$N爬上窗台，一个纵身，跳了下去。\n"NOR, me);
        me->move(__DIR__"gulou");
        message_vision(YEL"只听『砰』地一声$N从塔顶跳了下来。\n"NOR, me);

        if ( i < 180)
        {
                me->unconcious();
                message_vision(HIR"$N被摔得眼冒金星，顿时昏了过去。\n"NOR, me);
        }
        else {
                message_vision(HIW"$N凌空一个翻越，顿将下坠之势变为向前之势，已稳稳地站在地上，但也惊出了一身的冷汗。\n"NOR, me);
                if (me->query_skill("dodge",1)<200)
                {
                me->improve_skill("dodge", random(me->query("dex"))+30);
                }
                me->receive_damage("sen", 20 );
                me->receive_damage("gin", 20 );
                me->add("force", -5);
                me->start_busy(1);
        }

        return 1;
}






string look_drum()
{
        return
        "※※※※※※※※※※※※※※※※※※※※※※\n"
        "※※※※　　　　　　　　　　　　　　※※※※\n"
        "※※※※　　　　　佛语有曰：　　　　※※※※\n"
        "※※※※　　　　　　　　　　　　　　※※※※\n"
        "※※※※　『求一次菩萨，击一次鼓』　※※※※\n"
        "※※※※　　　　　　　　　　　　　　※※※※\n"
        "※※※※　　（ｈｉｔ　ｄｒｕｍ）　　※※※※\n"
        "※※※※　　　　　　　　　　　　　　※※※※\n"
        "※※※※※※※※※※※※※※※※※※※※※※\n";
}

string look_out()
{
        return  "这里是鼓楼顶层的窗台，从这里可以遥望整个少室山脉，\n"
"以及高耸入云的嵩山。浮世烟尘，尽在眼底。据说在此地\n"
"可以与天界诸佛直接交流，对禅修大有益处。\n";
}

