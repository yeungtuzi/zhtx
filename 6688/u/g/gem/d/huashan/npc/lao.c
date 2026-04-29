// laodenuo.c 劳德诺

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("劳德诺", ({ "lao denuo", "lao" }));
        set("title",GRN "华山派" NOR + YEL +"剑客" NOR);
        set("long",
                "他就是岳不群的二弟子老德诺。\n"
                "他年纪比大弟子令狐冲大，只是带艺投师，只能排老二了。\n");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 24);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 15000);
        set("score", 6000);

        set_skill("force", 100);
        set_skill("huashan-neigong", 100);
        set_skill("dodge", 100);
        set_skill("huashan-shenfa", 100);
		set_skill("cuff", 100);
		set_skill("poyu-quan", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("huashan-jianfa", 100);
//      set_skill("literate", 50);

        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
		map_skill("cuff", "poyu-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
		prepare_skill("cuff", "poyu-quan");

        create_family("华山派", 19, "弟子");


        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();

}

void attempt_apprentice(object ob)
{
        command("say 师傅没让我收徒。");
	return;
}

