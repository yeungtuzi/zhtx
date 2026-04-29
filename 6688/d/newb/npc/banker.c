///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////


#include <ansi.h>

inherit NPC;

void create()
{
        set_name("相国寿", ({"xiang guofu", "xiang" }));
        set("gender", "男性");

        set("long",
        "相国寿从小继承成祖业，过着逍遥的日子，养成了傲慢的性子，但他心地还是挺好的。\n");
        set("age", 35);

        set("combat_exp", 100000);
        set("attitude", "peacful");
        set("env/wimpy", 50);
        set("chat_chance", 3);
        set("chat_msg", ({
        YEL"相国寿傲然一笑，本钱庄已有二百多年历史，信誉卓著，你尽管放心。\n"NOR,
       CYN"相国寿忽然叹了一口气:什么时候我也能向玩家一样去纵横江湖，快意恩仇，那该多好啊！\n"NOR,
        }));

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

                if(exp<45000) {
                tell_object(ob,YEL"相国寿淡淡的看了你一眼，说道：在这儿可以存钱"HIW+" deposit "NOR+YEL"，\n"
                +"取钱"HIW+" withdraw "NOR+YEL"，查询存款"HIW+" balance "NOR+YEL"，兑换货币"HIW+" convert "NOR+YEL"。\n"
                +"相国寿说：你可以用"HIW+" help money "NOR+YEL"来了解更多。\n"NOR);
                }

}

