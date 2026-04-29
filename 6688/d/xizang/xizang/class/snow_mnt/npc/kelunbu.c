//
// by secret
// /d/xizang/class/snow_mnt/npc/kelunbu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("可伦布", ({ "kelunbu", "bu" }));
        set("long",@LONG
他是雪山寺中护寺僧兵的头领。同时向本寺第子传授武功。
身穿一件黑色袈裟，头带僧帽。
LONG
        );
        set("title", HIY "喇嘛" NOR);
        set("nickname", HIG "僧兵头领" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "heroism");
        set("str", 30);
        set("int", 20);
        set("con", 28);

        set("max_kee", 1000);
        set("max_gin", 600);
	set("max_sen", 600);
	set("shen", -1000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 20);
        set("combat_exp", 200000);
        set("score", 40000);
	set("pursuer", 1);

        set_skill("literate", 30);
        set_skill("force", 80);
        set_skill("xiaowuxiang-gong", 80);
        set_skill("dodge", 75);
        set_skill("notracesnow", 70);
        set_skill("parry", 60);
        set_skill("unarmed", 60);
	set_skill("move", 60);
        set_skill("nutrifux", 60);

        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");

        map_skill("move", "notracesnow");
        map_skill("parry", "nutrifux");
        map_skill("unarmed","nutrifux");

        create_family("雪山寺", 4, "大喇嘛");
        set("class", "lama");

        setup();

        carry_object(__DIR__"obj/b-jiasha")->wear();
        carry_object(__DIR__"obj/sengmao")->wear();
        carry_object(__DIR__"obj/senggun")->wield();

        add_money("silver",30);
}

void attempt_apprentice(object ob)
{
        command("say 我就传你一些武功吧！");
        command("recruit " + ob->query("id"));

        if((string)ob->query("class") != "lama") {
                ob->set("title","俗家弟子");
        }
        else    {
                ob->set("title",HIY"小喇嘛"NOR);
        }
}
