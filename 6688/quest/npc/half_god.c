inherit NPC;
#include <ansi.h>
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name(HIY "朱" NOR + HIG "半" NOR + HIM "仙" NOR, ({ "halfgod", "half god", "half-god" }) );
        
        set("gender", "男性");
        set("age", 99);
        set("long",
                "朱半仙年过六甲，鹤发童颜。\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "天机老人拿起旱烟抽了几口．．．．\n",
        }) );

        set("force", 800000);
        set("max_force", 800000);
        set("force_factor", 90000);
        set("atman", 1400);
        set("max_atman", 1400);
        set("mana", 4000);
        set("max_mana", 2000);
                                
        set("combat_exp", 10000000);
        set("score", 200000);

        set_skill("unarmed", 800);
        set_skill("parry",800);
        set_skill("force", 100);
       set_skill("perception",100);
        set_skill("iron-cloth", 900);
        set_skill("jin-gang",900);
        set_skill("celestial", 30);
        set_skill("dagger",200);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
        map_skill("iron-cloth", "jin-gang");
//        map_skill("iron-cloth", "celestial");
//         map_skill("force", "yiqiforce");
//        map_skill("unarmed", "yiqiforce");

        create_family("潇遥派", 1, "祖师");
        set("title", "闲云野鹤");
        setup();

//        carry_object(__DIR__"obj/jade-ring")->wear();
//        carry_object(__DIR__"obj/jade-pin")->wear();
//        carry_object(__DIR__"obj/jade-boots")->wear();
//        carry_object(__DIR__"obj/jade-cloth")->wear();
//        carry_object(__DIR__"obj/hanyan")->wield();
}
int accept_fight(object me)
{
        command("say 生命可贵！不要自寻死路！");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
}

