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
        set_name("村民", ({ "villager","村民"}) );
        set("gender", "男性" );
        set("age", 26);
        set("long","这是一个朴实的村民。\n");
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
                        if(random(2)==1)
                tell_object(ob,YEL"村民偷偷对你说道：你可以自己设置一些环境变量哦。请"HIW+" help settings "NOR+YEL"。\n"
                +"村民说：有空多看看"HIW+" help cmds "NOR+YEL"，你会找到一些有用的东西的。\n"NOR);
                else
                tell_object(ob,YEL"村民说道：有空可以去纵横天下的主页"HIW+" http://home.cd200.com/dongsw "NOR+YEL"和\n"
                +"纵横天下的论坛(从主页可进)看看，很有用的。\n"NOR);
                }

}


