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
        set_name("小青年", ({ "yong","qing nian","小青年"}) );
        set("gender", "男性" );
        set("age", 16);
        set("long","一个满脸稚气的小青年，无所事事的站在这儿。\n");
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
                tell_object(ob,YEL"小青年悄悄对你说道：行走江湖不会武艺可不行哦！你可以用指令"HIW+" skills "NOR+YEL"来查看你现在会的技能。\n"
                +"用"HIW+" help skills "NOR+YEL"可以知道更多关于技能的知识 。\n"NOR);
                tell_object(ob,YEL"小青年悄悄对你说道：迷路了吧？用指令"HIW+" help here "NOR+YEL"可以看到你现在所在地区的地图。\n"NOR);
                }
                if(ob->query("gender")!="女性")
                                return;
                if(ob->query("per")<=20 )
                        {
                                command("sigh "+ob->query("id"));
                                return;
                        }
                        command("kiss "+ob->query("id"));
        return;

}


