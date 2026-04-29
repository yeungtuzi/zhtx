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
        if( !ob || environment(ob) != environment() ) return;

                tell_object(ob,YEL"村民注意了到你，对你说道：想去附近的小岛？有船可以去。\n"
                +"你用"HIW+" yell fastboat "NOR+YEL"，等船来了再"HIW+" fastboat "NOR+YEL"就可以上船了。\n"
                +"村民对你说道：对了，过迷宫可是有技巧的哦。最好在每个房间\n"
                +"放上不同数量的coin，再看看哪些房间没到过。"HIW+" drop <数量> <物品> "NOR+YEL"会吧。\n"NOR);
}


