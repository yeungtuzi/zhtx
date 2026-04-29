// /d/xizang/class/snow_mnt/npc/xslama2.c
// by secret
// /d/xueshan/npc/seng-bing1.c
// 门卫

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("守寺喇嘛", ({
                "guard lama",
                "guard", "lama"
                "guardlm2"  }));
        set("long",
                "他是一位身材高大的壮年喇嘛，两臂粗壮，膀阔腰圆。他手持木\n"
                "禅杖，身穿一袭黑色袈裟，似乎怀有一身武艺。\n"
        );
        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");
        set("age", 25+random(20));
        set("str", 25+random(10));
        set("int", 20);
        set("con", 20);
        set("max_kee", 600);
        set("max_gin", 300);
	set("max_sen", 300);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 20);
        set("combat_exp", 20000);
        set("score", 1);
        set_skill("force", 50);
        set_skill("xiaowuxiang-gong", 50);
        set_skill("dodge", 50);
        set_skill("notracesnow", 50);
        set_skill("unarmed", 50);
        set_skill("nutrifux", 50);
        set_skill("parry", 50);
        set_skill("staff", 100);

        map_skill("move", "notracesnow");
        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");
        map_skill("unarmed", "nutrifux");
        map_skill("parry", "nutrifux");
        setup();

        carry_object(__DIR__"obj/staff")->wield();
        carry_object(__DIR__"obj/b-jiasha")->wear();
}
