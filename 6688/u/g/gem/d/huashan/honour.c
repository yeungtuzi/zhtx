#include <ansi.h>

inherit NPC;

void create()
{
        set_name("荣誉",({"rong yu","honour"}));
        set("long",@LONG
	醒时同交欢，醉后各分散，永结无情游，相期邈云汉。
	他在纵横上沉醉过一次，他爱过，他恨过，他苦过，
	风雨有本心，何求众人折？
	他的眼睛湛湛有神，有若黑夜中不灭的流星，诚如流
	星的悲哀一样，眼神中流淌出琢磨不透的忧郁。他茕
	然孑立，看花开花落，世态炎凉……
	别爱他别恨他别理他，闭上双眼……
LONG
        );
        set("nickname", CYN "采菊东篱下，悠然别泥巴" NOR);
        set("title",GRN "华山派" NOR + YEL "隐士" NOR);
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 60);
        set("int", 150);
        set("no_get",1);
        set("max_kee", 3000);
        set("max_gin", 1500);
        set("force", 6000);
        set("max_force", 3000);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("sen", 1000);
        set("max_sen", 1000);
        set("force_factor", 150);
        set("combat_exp", 5000000);
        set("score", 100000);
        set_skill("force",200);
        set_skill("zixia-shengong", 200);
        set_skill("dodge", 200);
        set_skill("huashan-shenfa", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("dugu-jiujian",200);
        set_skill("cuff", 180);
        set_skill("poyu-quan", 200);
        set_skill("perception", 150);
        set_skill("taiji-quan",180);
        set_skill("tiyun-zong",180);
        
        map_skill("cuff", "taiji-quan");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");
        prepare_skill("cuff", "taiji-quan");
        create_family("华山派",17,"弟子");

        setup();

	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/damage",300);
	set("env/attack",50);	

        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}

