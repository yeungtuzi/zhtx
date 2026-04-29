// /class/guard/npc/wisdomer.c
//with teller.c for telling some secrets to players by tlang
//wisdomer.c

#include <ansi.h>
inherit NPC;
#include <story_msg.h>

string story_status_msg();
void tell_story_msg1(object who,int stage);
void tell_story_msg2(object who,int stage);
void tell_story_msg3(object who,int stage);
int do_talk(string arg);
void make_talk(object who, int stage);
void go_come();
void go_now();
int dest();
void ask_pu();

string *make_msg = ({
    YEL "一会儿里面传来两个人的说话声。\n\n" NOR,
    YEL "似乎是一个人在问别人什么问题。\n\n" NOR,       
    YEL "你仔细一听，却又什么也听不见。\n\n" NOR,
    YEL "后来似乎一个人很高兴，哈哈大笑了几声。\n\n" NOR,
    YEL "笑声特别怪异，你觉得耳熟，一下又想不起在哪儿见过。\n\n" NOR,
});                         

void create()
{
   set_name(YEL"盲眼老儿"NOR, ({"mangyan laoer", "wisdomer"}) );
   set("long", "据说他只有他能和当今世界之大智大通之人说话，从而知道
各种秘密。\n");
   set("per", 10+random(10));
   set("int", 30);
   set("str", 10+random(10));
   set("gender", "男性");
   set("age", 80+random(20));
   set("combat_exp", 10000+random(1000000));
   set("max_kee", 3000);
   set("max_mana", 1500);
   set("max_atman",1500);

   set("chat_chance_combat",60);
   set("chat_msg_combat", ({
           (: random_move :),
   }));

       set("inquiry",([
                "纵横兵器谱"    : (: ask_pu :),
        ]));

   set("count", 1);
   add("gold", 1);
   setup();
   carry_object("/obj/cloth/cloth")->wear();
   call_out("dest",800);
}

void init()
{       
   object ob=this_player();

   ::init();
   add_action("do_talk","talk");
   remove_call_out("greeting");
   call_out("greeting",5,ob);
}      

void greeting(object ob) 
{       
        if( !ob || environment(ob) != environment() )
           return;
   else if(!ob->query("my_leader") )
   {
           command("hi "+ob->query("id"));
                   return;
   }
        command("smile "+ob->query("id"));
}                                   

int accept_object(object who, object ob)
{
   if( query("count")<1 )
   {       
           command("sigh "+who->query("id"));
           command("say 今天我已经收过别人的东西了。等下次吧。\n");        
                   return 0;
   }
   if(ob->value() <5000)
   {
           command("heng "+who->query("id"));
           command("太便宜了吧。\n");
                   return 0;
   }
   destruct(ob);
   command("say 带我到杭州城外的山洞去吧。\n");
   who->set("my_leader",1);
   this_object()->set_leader(who);
   add("count", -1);
           return 1;
}

int do_talk(string arg)
{
   object ob=this_player();
   object me=this_object();
           
   if(!arg || arg!=me->query("id") )
   {
           command("kick "+ob->query("id"));
           command("say 我眼睛瞎，你也瞎啊？连说话对象都看不清。\n");
                   return 0;
   }
   if(!ob->query("my_leader") )
   {
           command("hehe "+ob->query("id"));
           command("say 总的有点代价吧？\n");
                   return 0;
   }
   if(ob->query("my_leader") && !environment(ob)->query("my_target") )
   {
           command("kick "+ob->query("id"));
           command("say 你欺负我眼瞎是不是？还没到呢。\n");
                   return 0;
   }
   me->set_leader(0);      
   command("nod "+ob->query("id"));
   command("say 你在外面等一会儿。\n");
           command("west");
   remove_call_out("make_talk");
   call_out("make_talk",1,this_player(),0);        
           return 1;
}

void make_talk(object who, int stage)
{                       
        tell_object(who, make_msg[stage]);
        
        if( ++stage < sizeof(make_msg) ) {
                call_out( "make_talk", 3, who, stage );
                return;
        } 
   tell_object(who, YEL "里面的谈话终于完了!\n" NOR);
   remove_call_out("go_come");
   call_out("go_come", 2);
}
                  
void go_come()
{
   string secret;

// secret=secret_msg[random(sizeof(secret_msg))];
   secret=story_status_msg();
   command("east");
   if(this_player()->query("my_leader") ) 
   {
           command("pat "+this_player()->query("id"));
           command("whisper "+ this_player()->query("id") + " "+secret +" \n");
           this_player()->delete("my_leader");
           call_out("go_now",30);
                   return;
   }
   command("chat 再见了。");
   call_out("dest",5);
}

void go_now()
{
	if ( this_player()->query("kar") > 20 )
	{
		command("duh");
		command("whisper "+ this_player()->query("id") + " 我差点忘了告诉你，你很幸运，这次我还打听到关于一本古书的事情，这本书叫做《纵横兵器谱》，几十年前曾经有人见过，据说有神奇的作用。\n");
		this_player()->set_temp("weaponor1",1);
	}

   command("bye "+this_player()->query("id"));
   command("west");
   call_out("dest",5);
}

int dest()
{
   command("bye");
   destruct(this_object());
}

void ask_pu()
{
	if (!this_player()->query_temp("weaponor1")) return;
	command("whisper " + this_player()->query("id") +" 三十年前听木道人提到过一次，据说此书有神秘的作用。");
	call_out("dest",5);
}
