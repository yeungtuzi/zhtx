// /d/xizang/class/snow_mnt/npc/jiumozhi.c
// /kungfu/class/xueshan/jiumozhi.c 鸠摩智
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("鸠摩智", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "大轮明王" NOR);
        set("long",@LONG
他就是雪山寺的掌门，人称大轮明王的鸠摩智。他对佛法有精深的研究。
身穿一件大红袈裟，头带僧帽。
LONG
        );
//       set("title","雪山寺掌门");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("max_kee", 5000);
        set("max_gin", 5000);
	set("max_sen", 5000);
	set("shen", -600000);
        set("force", 10000);
        set("max_force", 5000);
        set("force_factor", 240);
        set("combat_exp", 3000000);
        set("score", 500000);

        set_skill("force", 200);
        set_skill("xiaowuxiang-gong", 200);
        set_skill("dodge", 200);
        set_skill("notracesnow", 200);
        set_skill("unarmed", 200);
        set_skill("nutrifux", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 200);
        set_skill("literate", 100);
	set_skill("zang-buddhi", 200);
	set_skill("move", 200);

        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");
        map_skill("move", "notracesnow");
        map_skill("unarmed", "nutrifux");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");

        create_family("雪山寺", 2, "住持");
        set("class", "lama");

        setup();

        carry_object(OBJ_DIR"weapon/changjian")->wield();
        carry_object(__DIR__"obj/y-jiasha")->wear();
        carry_object(__DIR__"obj/sengmao")->wear();

        add_money("gold",5);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "男性") {
        	command("say 我只收男弟子。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
        return;
	}
	if ((string)ob->query("class") != "lama") {
        	command("say 我只收喇嘛教徒作为弟子。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
	}
        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
	}
        if ((int)ob->query_skill("xiaowuxiang-gong", 1) < 100) {
        command("say 你的功夫太差,还是先和拉章大法师学学基本功夫吧。");
                return;
        }
	command("say 好,那我就收下你,希望你能光大本寺,护法卫道.");
        command("recruit " + ob->query("id"));
	ob->set("title",HIY"大法师"NOR);
}
