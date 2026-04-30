//write by lysh
// Mon  08-21-95

inherit NPC;
void new_oldwoman();
void ask_for_help();
void wield_something();
int ask_jitang(); 
void create()
{
        // 2026-04-30: unused variable commented out
        // int has_game;
        seteuid(getuid());
        set_name("老公公",({"old man", "oldman", "man"}));
        set("long", @TEXT
TEXT
        );
        set("gender","男性");
        set("age",77);
        set("combat_exp",70);
        set("attitude","friendly");
        set("inquiry", ([
                "鸡汤" : (: ask_jitang :),
        ]));

        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
        (: ask_for_help :),
        (: wield_something :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/dagger");
        add_money("coin",100);
}
 
void wield_something()
{
	if (!query_temp("weapon")) command("wield dagger");
        return;
}
 
void ask_for_help()
{
        object helper;
        helper = present("old woman", environment(this_object()));
        if (!helper || helper->is_fighting()) return;
        tell_room(environment(helper), helper->name()+"喊道: "+
        "老伴我来帮你了!\n", ({this_object(), helper}) );
        helper->kill_ob(query_temp("killer"));
        return;
}
 
void kill_ob(object ob)
{
        set_temp("killer",ob);
        ::kill_ob(ob);
}
int ask_jitang()
{       
        if(this_player()->query_temp("acc-ji"))
       { command("say 等我老伴病好了，让她给你炖最香的鸡汤");
          return 1;
        }
        if(this_player()->query_temp("know_ji"))
     { 	command("say 我老伴已经病的不行了，怎么能做鸡汤呢。");
        command("say 她现在最想吃滋补美味的银鱼汤。");
        this_player()->set_temp("get-yu",1);
        this_player()->set_temp("know_ji",0);
      }
       	return 1;
}
int accept_object(object ob, object obj)
{
     if(!ob->query_temp("got-yu"))return 0;
     if(obj->query("id")!="yu rou")return 0;
     command("say 啊！这正是银鱼肉，多谢了。等我老伴病好了，让她给你炖最香的鸡汤");
     ob->set_temp("acc-ji",1);
     ob->set_temp("got-yu",0);
     remove_call_out("new_oldwoman");
     call_out("new_oldwoman",30);
     return 1;
 
}
void new_oldwoman()
{
  object obj1,obj2;
  obj1=present("old woman",environment(this_object()));
  if(!obj1)return;
   destruct(obj1);
   obj2=new("/adm/npc/oldwoman1");
   obj2->move(environment(this_object()));
   return;
}
