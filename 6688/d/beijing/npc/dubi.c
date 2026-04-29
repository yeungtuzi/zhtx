// 9nan.c 
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("九难师太", ({ "jiunan shitai", "shitai","jiunan" }));
	set("gender", "女性");
	set("age", 44);
	set("str", 25);
	set("con", 20);
	set("long", "这是一位白衣女尼，手握拂尘，目视前方。\n"+
	"一只长袖空空如也，显是断了一臂，尽管如此，\n"+
	"仍然掩不住她迷人的风采。\n");
	set("combat_exp", 2000000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("whip", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("fall-steps", 150);
	set_skill("snowwhip", 150);
	map_skill("whip", "snowwhip");
	map_skill("parry", "snowwhip");
	map_skill("dodge", "fall-steps");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("force", 1500); 
	set("max_force", 1500);
	set("force_factor", 100);
        set("inquiry", ([
                "珂珂" :  "九难师太叹了一口气，说道：她是我的得意弟子，\n人长得挺美，唉，只可惜被韦小宝骗去了。\n",
       ]) );
	setup();
        carry_object(__DIR__"obj/fuchen")->wield();
	carry_object(__DIR__"obj/daopao")->wear();
	add_money("gold", 2);
}

void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
	int i;	
	object man,*obj;
	if( !ob || environment(ob) != environment()) return;
    
	if((int)ob->query_temp("hastrystab")==6)
	{
	message_vision(HIC "$N踏进屋来，只见地上尸体横陈，一个女尼喘息不止。\n" NOR,ob);		
	ob->delete_temp("hastrystab");
	ob->delete_temp("warned2");
	message_vision("\n白衣女尼对$N说道：“多谢这位"+RANK_D->query_respect(ob)+
	"拔刀相助，贫尼感激不尽，无以为报。\n",ob);
	ob->set("save9nan",1);
	set_leader(ob);
	}
	return;
}