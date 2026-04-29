// /d/xizang/class/snow_mnt/npc/lingzhi.c
// /kungfu/class/xueshan/lingzhi.c  灵智上人
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("灵智上人", ({ "lingzhi shangren", "shangren" }));
        set("long",@LONG
灵智上人是雪山寺中地位较高的喇嘛。他本是班禅大师的弟子,不知为什么
自大招寺叛逃而来.他身穿一件青色袈裟，头带僧帽。
LONG
        );
        set("title",HIY "大喇嘛" NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
//        set("shen_type", -1);
	set("shen", -25000);
        set("str", 25);
        set("int", 27);
        set("con", 28);
        set("cor", 26);
        set("max_kee", 1500);
        set("max_gin", 1500);
	set("max_sen", 1500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 20);
        set("combat_exp", 500000);
        set("score", 80000);

        set_skill("bolomiduo", 60);
        set_skill("literate", 60);
        set_skill("force", 100);
        set_skill("xiaowuxiang-gong", 80);
        set_skill("dodge", 100);
        set_skill("notracesnow", 80);
        set_skill("parry", 80);
        set_skill("staff", 60);
        set_skill("cloudstaff", 80 );
        set_skill("unarmed", 110);
        set_skill("bloodystrike", 100);

        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");
        map_skill("unarmed", "bloodystrike");
        map_skill("parry", "bloodystrike");
        map_skill("staff", "cloudstaff");

        create_family("雪山寺", 4, "大喇嘛");
        set("class", "lama");

        setup();

        carry_object(__DIR__"obj/c-jiasha")->wear();
        carry_object(__DIR__"obj/sengmao")->wear();
	carry_object(__DIR__"obj/bo")->wield();
	carry_object(__DIR__"obj/bo");
	carry_object(__DIR__"obj/staff")->wield();

        add_money("gold",1);
}

void attempt_apprentice(object ob)
{
        command("say 就传你一些武功吧！");
        command("recruit " + ob->query("id"));

	if((string)ob->query("class") != "lama") {
                ob->set("title","俗家弟子");
        }
        else    {
        ob->set("title",HIY "小喇嘛" NOR);
	}
}
