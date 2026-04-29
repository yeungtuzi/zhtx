// smith.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string *leave_msg = ({     
	YEL"铁匠加紧了拉风箱的频率，把炉火烧得更旺了。 \n",NOR
	YEL"铁匠把九块软铁投进炉中煅烧起来。不一会儿软铁就被烧的通红了。\n",NOR
	YEL"铁匠用铁钳把一块软铁夹了出来，挥动烧红的铁锤一阵锤打，把第一块软铁打成了鞭柄。\n",NOR
	YEL"铁匠夹出第二块软铁，打成了鞭身的一环，并衔接在了鞭柄上。 \n",NOR
	YEL"。。。。。。\n",NOR
	YEL"。。。。。。\n",NOR
	YEL"铁匠把最后一块软铁打成了鞭梢，把它衔接在鞭尾上。\n",NOR
	YEL"铁匠说道：“成了，等我把它淬火降温了，你就可以用了。”\n",NOR
	YEL"铁匠把九节鞭投进水里，只见一阵白汽从水池中冒出来，并发出\n"+
	   "“滋滋”的声音，九节鞭由通红变成了正常的颜色。\n",NOR
	});
void create()
{
	set_name("铁匠", ({ "smith" }) );
	set("gender", "男性" );
	set("age", 43);
	set("long", 
"铁匠在京开打铁铺子已经好多年了，他手艺很好，在这里人缘又好，\n"
"这附近的人都爱到他这里定做一些农具或刀具。听说他对打造兵器也\n"
"是非常的拿手。\n");
	set("combat_exp", 250000);

        set("str", 24);
        set("con", 28);
        set("int", 27);
	set("shen_type", 1);

        set("attitude", "friendly");
        set_skill("dodge", 100);
	set_skill("hammer",100);
	set_skill("parry", 100);
        set_skill("force", 100);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set("vendor_goods", ([
                __DIR__"obj/hammer":10,
		__DIR__"obj/dart":10,
		__DIR__"obj/whip":10,
        ]));
	set("inquiry", ([
		"here": "这里是小人糊口的铺子，小人就住在後边的屋子。",
		"锄头": "锄头... 你改天在来吧，我现在正忙着做一个大活计。",
		"铁锤": "铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。",
		"软铁"  : 
"哦，那可是打造九节鞭的好材料啊！可惜我只是听我师傅说过。却没有\n"
"见过，如果你手中有软铁，我可以试着替你打造一把好鞭！。",
		"九节鞭": "九节鞭乃用九块软铁打造衔接而成，有较强的攻防能力。",
	]) );
	setup();
        add_money("silver", random(10));
        carry_object(__DIR__"obj/hothammer")->wield();
}

void leave_stage(object who, int stage)
{
	object whip;
	whip = new(__DIR__"obj/9whip");
        tell_object(who, leave_msg[stage]);
        if( ++stage < sizeof(leave_msg) ) {
        call_out( "leave_stage", 3, who, stage );
        return;
     } 
        else say(
"铁匠说道：这柄"+ whip->query("name")+ "可是小人的心血，你可要好好利用啊。\n"
"铁匠把" + whip->query("name") + "交给了" + who->query("name") + "。\n");
		whip->move(who);
                set("9whip_trigger", 1);
}

int accept_object(object who, object ob)
{

	int times;
	times = who->query("marks/ruantie");
        if (!userp(ob) && (string)ob->query("id")=="ruantie") 
	    {
	     destruct(ob);
	     if(times<8)
		{ who->add("marks/ruantie",1);
		  say(
"铁匠说道：“你还得再给我"+chinese_number(8-times)+"块软铁我才能替你打造九节鞭！”\n");
		  return 1;
		}
	     else if(!query("9whip_trigger")) {
		who->start_busy(10); 
		say("铁匠说道：“太好了，你找到了九块软铁，我可以为你打造一条九节鞭。”\n");
		who->set("marks/ruantie",0);
		call_out( "leave_stage", 2, this_player(), 0 );		
              }
           else say("铁匠眼也不抬，疲惫地说道：我今天太累了。你改天再来好了。\n");
		who->set("marks/ruantie",0);
             	return 1;
	 }	
	return 0;
}
