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
        set_name("村长的儿子", ({ "son","村长的儿子"}) );
        set("gender", "男性" );
        set("age", 36);
        set("long","他是老村长的儿子，一眼看去就知道是个朴实，诚恳的中年汉子。\n"
                                                +"为了建好新手村，陪着老村长忙前忙后，可把他累坏了。\n");
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

                if(exp<20000) {
                tell_object(ob,YEL"村长的儿子冲你憨厚的笑了笑，对你说道：累了吧？在这儿可以睡觉("HIW+" sleep "NOR+YEL")。\n"
                +"睡觉以后你的精，气，神都会全满。不过老贪睡也不行哦。\n"NOR);
                tell_object(ob,YEL"村长的儿子对你说道：对了，你可以用指令"HIW+" i "NOR+YEL"来看你身上带的东西，\n"
                +"用指令"HIW+" id "NOR+YEL"和"HIW+" id here "NOR+YEL"来看你周围物品的名称。不清楚的话可以"HIW+" help id "NOR+YEL"。\n"NOR);
                }

}


