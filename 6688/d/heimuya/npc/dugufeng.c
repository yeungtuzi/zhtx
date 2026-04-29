// by yeung
// 1/14/99

#include <ansi.h>

inherit __DIR__"zhanglao";
inherit "/feature/challenge";

void create()
{
	set_name("独孤峰", ({ "dugu feng", "dugu", "feng" }));
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");	
	set("nickname",HIB "剑痴神魔"NOR);	
	set("long", @LONG
独孤峰是十大长老之首,东方不败不知所踪之后,日月教日常的事务都由
杨莲亭把持,但是真正最有影响的还是这位长老.只不过他一生献身剑道，
对别的事情很少理会。他神色冷然，脸上从来没有露出过什么笑意。
最近正派中人常常到神教来挑衅生事,一般都由他出面应付.
LONG	
	);
	set("gender", "男性");
	set("age", 51);
	set("attitude", "heroism");
	set("shen_type", -1);
	//想得50万正气,不怕死的就来吧,嘿嘿
	set("shen",-5000000);
        set("cps", 50);
        set("cor", 50);
        set("int", 50);
	
	set("max_kee", 5000);
	set("max_gin", 1500);
	set("max_sen", 1500);
	set("force", 8000);
	set("max_force", 4000);
        set("max_atman", 2000);
        set("atman", 2000);
	set("force_factor", 150);
	set("combat_exp", 5000000);

        set_skill("perception",180);
	set_skill("force", 180);
	set_skill("tianmo-dafa", 200);
	set_skill("dodge", 180);
	set_skill("mo-shan-jue", 200);
        set_skill("strike", 180);
	set_skill("mo-zhang-jue", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("mo-jian-jue", 200);  
	set_skill("move",180);


	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("sword","mo-jian-jue");
        map_skill("parry","mo-jian-jue");    
        map_skill("move","mo-shan-jue");
        prepare_skill("strike", "mo-zhang-jue");

	create_family("日月神教", 14, "长老");

	setup();
        carry_object("/d/heimuya/obj/coolsword")->wield();
	suit = new("/obj/cloth");
	suit->move(this_object());
	suitname = query("nickname");
	suit->set("name",suitname+suit_name[random(sizeof(suit_name))]);
	suit->wear();	
//          set("bellicosity",3000);
        set_temp("apply/attack",100);
        set_temp("apply/defense",50);
	set_temp("apply/damage",200);
	set_temp("apply/armor",200);
	set_temp("apply/armor_vs_force",200);	
}
