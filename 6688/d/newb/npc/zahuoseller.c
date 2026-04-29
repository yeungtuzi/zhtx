///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        object ob;
        set_name("梁掌柜", ({ "liang","boss","梁掌柜"}) );
        set("gender", "男性" );
        set("age", 46);
        set("long","一个满脸倦色的中年男子。常年在店里忙碌，可把他累坏了。\n");
        set("combat_exp", 90000);

        carry_object("/obj/cloth")->wear();
        set("vendor_goods", ([
                                __DIR__"obj/shuji1": 20,
                                __DIR__"obj/shuji2": 20,
                                __DIR__"obj/force_book": 20,
                                "/obj/drug/slumber_drug": 1,
                                "/obj/example/bag": 30,
                                "/obj/example/pear": 6,
                                "/obj/map/map": 6,
                                "/obj/toy/birthday": 2,
        ]));
        setup();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");

}

void greeting(object ob)
{
                int exp;
        if( !ob || environment(ob) != environment() ) return;
        exp=ob->query("combat_exp");

                if(exp<50000) {
                tell_object(ob,YEL"梁掌柜没精打采的对你说道：这儿也卖书哦。拿到书可以用指令"HIW+" study "NOR+YEL"来读。\n"
                +"不清楚的话可以"HIW+" help study "NOR+YEL"。读“内功心法入门”可以提高内功等级，内功可是\n"
            +"非常有用的哦。你可以用"HIW+" help book "NOR+YEL"和"HIW+" help force "NOR+YEL"来了解更多情况。\n"
                +"这里卖的地图有点旧了，你可以用"HIW+" help maps "NOR+YEL"来了解纵横天下的地图。\n"NOR);
                }

}


