//ychzhi.c write by lysh叶诚治

inherit NPC;
inherit "/std/char/qlist.c";
int ask_zi();
void create()
{
	set_name("叶诚治", ({ "ye cheng zhi", "ye", "zhi" }));
	set("age", 54);
	set("gender", "男性");
	set("long", "一位长须垂胸的慈祥老者。\n");
	set("attitude", "friendly");

	set("str", 24);
	set("con", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("force", 40);
        set_skill("literate",100);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

        set("chat_chance", 1);
	set("chat_msg", ({
		"鄙人平生最喜好风雅之事，舞文弄墨，写诗做画，养花弄草。\n",
		}));
               set("inquiry", ([
                "字画" : (: ask_zi :),
        ]));

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

int ask_zi()
{       
        
	command("say 鄙人最爱的是茶花中的极品“十八学士”，如果"+ RANK_D->query_respect(this_player())+ "能送我一株“十八学士”，我就给你我珍藏的字画。");
	this_player()->set_temp("ask-zi", 1); 
        
	return 1;
} 

int accept_object(object ob, object obj)
{
	object obj1,obj2;
	object me=this_object();   
        
        if ((obj->query("id")=="shi ba xue shi")&&(ob->query_temp("ask-zi")))
         {   
         command("say 这不是“十八学士”，而是“落地秀才”，两者虽貌似，但价值迥异。");
         ob->set_temp("foolish",1);
         ob->set_temp("ask-zi",0);
         return 0;
          }


	 if ((ob->query_temp("get-flower"))&&(obj->query("id")=="ye hua")&&(obj->name(1)=="野花")) 
          {                            
            command("say 这正是鄙人梦寐以求的“十八学士”!");
            command("say 我无以回报，就把这珍藏的字画赠给你。");
            obj2=new(__DIR__"obj/zihua.c"); 
            obj2->move(ob);
            write("叶诚治给你一幅字画。\n");   
             deal_quest(ob,"字画");  
            remove_call_out("destroying");
            call_out("destroying", 1, ob, obj);
             return 1;
            }
           
      
}


void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
