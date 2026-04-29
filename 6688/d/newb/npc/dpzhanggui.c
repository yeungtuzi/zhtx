///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit NPC;

void create()
{
        object ob;
        set_name("当铺掌柜", ({ "zhang gui","boss","当铺掌柜"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long","一位胖胖的中年男子，从事当铺行业已有多年。\n");
        set("combat_exp", 60000);

        carry_object("/obj/cloth")->wear();
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
}

void greeting(object ob)
{
                int exp;
        if( !ob || environment(ob) != environment() ) return;
        exp=ob->query("combat_exp");

                if(exp<50000) {
                tell_object(ob,YEL"当铺掌柜对你作了个揖，说道：欢迎惠顾！在这儿可以典当("HIW+" pawn <物品>"NOR+YEL")各种\n"
                +"物品，查看已经典当的所有物品("HIW+" pawn "NOR+YEL")，需要的时候也可以赎回("HIW+" redeem "NOR+YEL")你\n"
                +"典当的物品。另外你也可以把东西卖("HIW+" sell "NOR+YEL")给我，也可以先估价("HIW+" value "NOR+YEL")，看看\n"
                +"是不是很贵重。\n"NOR);
                }

}


