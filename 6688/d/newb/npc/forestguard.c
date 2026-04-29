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
        set_name("看林老头", ({ "guard","old man"}) );
        set("gender", "男性" );
        set("age", 66);
        set("long","这是一位面色红润，精神矍铄的老者。在这儿看管这片森林，只有适合狩猎的\n季节才会让村里的人去打猎。\n");
        set("combat_exp", 60000);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("chat_chance",5);
        set("chat_msg", ({
                "看林老头说道：在这儿打猎可别忘了带好弓箭啊。\n",
                "看林老头说道：在这儿有不少珍稀的动物。\n",
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

                if(exp<20000) {
        message_vision(CYN"看林老头淡淡的看了$N一眼，说道：这位" + RANK_D->query_respect(ob)+"有何贵干啊?\n"
                        "看林老头说：你的经验还不太够，不适合在这儿打猎。\n"NOR,ob);
                tell_object(ob,YEL"看林老头对你说道：你可以考虑去习字或者钓鱼增加经验。\n"NOR);
                }
        else if(exp<50000) {
                        message_vision(CYN"看林老头看了$N一眼，说道：这位" + RANK_D->query_respect(ob)+"是来打猎的吧?\n"
                                "在这儿打猎可别忘了带好猎弓。猎弓可以去村里的武器店买。买好猎弓，装备好\n"
                                "(wield bow)就可以了。从这儿往北去就是林区了。现在是适合狩猎(hunt)的季节，呵呵。\n"NOR,ob);
                        tell_object(ob,YEL"看林老头对你说道：在这儿打猎还可以增加经验和潜能哦！\n"NOR
                        YEL"看林老头说：打来的猎物可以拿到村里的当铺或者是商店去卖(sell)。\n"NOR);
                }
                else {
        message_vision(CYN"看林老头淡淡的看了$N一眼，说道：这位" + RANK_D->query_respect(ob)+"有何贵干啊?\n"
                        "看林老头说：在这儿打猎已经不会对你的成长有任何帮助了。\n"NOR,ob);
                tell_object(ob,YEL"看林老头对你说道：你可以考虑离开新手村，到外面的真正的江湖去闯荡了。\n"
                +"你可以去向老村长打听怎么出村："HIW+" ask <老村长> about 出村 "NOR+YEL"就可以了。\n"NOR);
                }
}


