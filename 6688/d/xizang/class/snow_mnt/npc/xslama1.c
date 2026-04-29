// /d/xizang/class/snow_mnt/npc/xslama1.c
// by secret
// /d/xueshan/npc/seng-bing1.c
//

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("守寺喇嘛", ({
                "guard lama",
                "guard", "lama"
                "guardlm1"  }));
        set("long",
                "他是一位身材高大的壮年喇嘛，两臂粗壮，膀阔腰圆。他手持木\n"
                "禅杖，身穿一袭黑色袈裟，似乎怀有一身武艺。\n"
        );
        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "lama");
        set("age", 25+random(20));
        set("str", 25+random(10));
        set("int", 20);
        set("con", 20);
        set("max_kee", 500);
        set("max_gin", 300);
	set("max_sen", 300);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 10);
        set("combat_exp", 10000);
        set("score", 1);
        set_skill("force", 50);
        set_skill("xiaowuxiang-gong", 50);
        set_skill("dodge", 50);
        set_skill("notracesnow", 50);
        set_skill("unarmed", 50);
        set_skill("nutrifux", 50);
        set_skill("parry", 50);
        set_skill("staff", 80);
	set_skill("move", 30);
        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");
        map_skill("move", "notracesnow");
        map_skill("unarmed", "nutrifux");
        map_skill("parry", "nutrifux");
        setup();

        carry_object(__DIR__"obj/staff")->wield();
        carry_object(__DIR__"obj/b-jiasha")->wear();
}

void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob)
        && !environment(ob)->query("no_fight")
        && ((fam=ob->query("family"))
        && fam["family_name"]!="雪山寺" ))
        {
                if( !ob->query_temp("warned") ) {
                        command("say 你是谁？怎么闯入雪山寺来了！！\n");
                        command("say 快给我速速离开，下次看到决不轻饶！");
                        ob->set_temp("warned", 1);
                }
        else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        command("say 大胆狂徒，受死吧！\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
        }
}
