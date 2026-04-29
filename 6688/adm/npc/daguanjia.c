//write by lysh
#include <ansi.h>
inherit NPC;
inherit "/std/char/qlist.c";
int do_accept(string);
void pre_cal(int baozi);
int ask_du();
void create()
{
	int i,amun;
	set_name( "大管家", ({ "da guan jia","da","jia" }) );
	set("long", "这是长安赌坊的大管家，骰子上的功夫深不可测。\n");
	set("attitude", "friendly");
        set("force_factor", 30);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 99999);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
	set("age", 33);
	set_temp("apply/damage",600);
            
        set("gender", "男性" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per",10);
	set("too_late",0);
	set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
	set("max_force",400000);
	set("force_factor",250);
	set_skill("throwing",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set("combat_exp", 50000000);
	setup();
        set("inquiry",([
               "赌"  : (: ask_du :),
        ]));
   
        carry_object("/obj/cloth")->wear();
	
}
void init()
{
   add_action("do_accept","accept");
}         
 
string *dice = ({
"[31m
	⊙ 

[37m",
"	⊙

	    ⊙
",
"	⊙
	  ⊙ 
	    ⊙
",
"	[31m⊙  ⊙

	⊙  ⊙
[37m",
"	⊙  ⊙
	  ⊙
	⊙  ⊙
",	
"	⊙ ⊙
	⊙ ⊙
	⊙ ⊙
"
		});

int ask_du()
{
if(this_object()->query("too_late"))
{write("大管家冷冷的说：“我现在没空和你赌。”\n");
return 0;}
tell_object(this_player(),"大管家冷冷的对你说：“赌掷骰子，比大赌命，一把定乾坤。”(accept yes/no)");
this_player()->set_temp("accepted",1);
return 1;
}
int do_accept(string arg)
{	int baozi;
        if(!this_player()->query_temp("accepted")) return 0;
        if (!arg || (arg!= "yes" && arg !="no")) return 0;
        if (arg=="yes")
      {  baozi= (int) this_player()->query("baozi");
         this_object()->set("too_late",1);
         this_player()->set_temp("accepted",0);
  	message_vision("$N将手中的三粒骰子撒向碗里．\n",this_object());
	message_vision("\n．．．三粒骰子在碗里蹦跳着，发出悦耳的声音．．．\n",this_object());
	pre_cal(baozi);
        call_out("first_dice",3);
	return 1;}
}

void first_dice()
{
	int first;
        switch( random(3) ) {
                case 0:
        message_vision("\n一粒骰子弹了几下，停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n一粒骰子＂叮叮叮＂的跳动了几下，缓缓的停了下来：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n三粒骰子相互一撞，一颗直落碗底：\n\n",this_object());

                        break;
        }

	first = (int) this_object()->query("first_dice");
	message_vision(dice[first], this_object());
	this_object()->set("first_dice",first+1);
	call_out("second_dice",4);
return;
}

void second_dice()
{
	int second;
        switch( random(3) ) {
                case 0:
       message_vision("\n又一粒骰子缓缓的停了下来：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n第二粒骰子在碗边旋转不停．．忽地翻了个身：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n二粒骰子相互一撞，其中一颗跳了一跳：\n\n",this_object());

                        break;
        }
        second= (int) this_object()->query("second_dice");
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
	call_out("third_dice",4);


return;
}
void third_dice()
{
        int third;
        switch( random(3) ) {
                case 0:
       message_vision("\n最后一粒骰子在碗里滑了两下，终于停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n还有最后一粒骰子嘀遛遛的转个不停．．终于：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n最后一粒骰子也终于停稳了：\n\n",this_object());

                        break;
        }
        third= (int) this_object()->query("third_dice");
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("me_start",5);

return;
}

int me_start()
{
	message_vision("$N将手中的三粒骰子撒向碗里．\n",this_player());
	message_vision("\n．．．三粒骰子在碗里蹦跳着，发出悦耳的声音．．．\n",this_object());
        call_out("forth_dice",1);
	return 1;
}


void forth_dice()
{
	int forth;
        switch( random(3) ) {
                case 0:
        message_vision("\n一粒骰子弹了几下，停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n一粒骰子＂叮叮叮＂的跳动了几下，缓缓的停了下来：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n三粒骰子相互一撞，一颗直落碗底：\n\n",this_object());

                        break;
        }

	forth = (int) this_object()->query("forth_dice");
	message_vision(dice[forth], this_object());
	this_object()->set("forth_dice",forth+1);
	call_out("fifth_dice",3);
return;
}


void fifth_dice()
{
	int fifth;
        switch( random(3) ) {
                case 0:
       message_vision("\n又一粒骰子缓缓的停了下来：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n第二粒骰子在碗边旋转不停．．忽地翻了个身：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n二粒骰子相互一撞，其中一颗跳了一跳：\n\n",this_object());

                        break;
        }
        fifth= (int) this_object()->query("fifth_dice");
        message_vision(dice[fifth], this_object());
        this_object()->set("fifth_dice",fifth+1);
	call_out("sixth_dice",4);


return;
}

void sixth_dice()
{
        int sixth;
        switch( random(3) ) {
                case 0:
       message_vision("\n最后一粒骰子在碗里滑了两下，终于停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n还有最后一粒骰子嘀遛遛的转个不停．．终于：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n最后一粒骰子也终于停稳了：\n\n",this_object());

                        break;
        }
        sixth= (int) this_object()->query("sixth_dice");
        message_vision(dice[sixth], this_object());
        this_object()->set("sixth_dice",sixth+1);
        call_out("end_the_round",3);

return;
}


void end_the_round()
{
	int tot,reward,i,first, second, third, forth,fifth,sixth;
        int laoban,you;
	object *inv;
	first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");
        forth = (int) this_object()->query("forth_dice");
        fifth = (int) this_object()->query("fifth_dice");
        sixth = (int) this_object()->query("sixth_dice");
        laoban=first+second+third;
        you=forth+fifth+sixth;
        if(you<laoban)
        {
        tell_object(this_player(),"大管家狞笑一声：“你输了，拿命来吧。”");
        this_player()->die();
        }
        else
         {
          this_player()->set_temp("enter-two",1);
          tell_object(this_player(),"大管家诚惶诚恐的说：“骰子高手请进。”");
          deal_quest(this_player(),"赌赢管家");

          }
this_object()->set("too_late",0);
this_object()->set("first_dice",0);
this_object()->set("second_dice",0);
this_object()->set("third_dice",0);
this_object()->set("forth_dice",0);
this_object()->set("fifth_dice",0);
this_object()->set("sixth_dice",0);
return;
}

void pre_cal(int baozi)
{
int i,win;
object con,*inv;
string objname;

win=0;
this_object()->set("first_dice",random(2)+4);
this_object()->set("second_dice",random(2)+4);
this_object()->set("third_dice",random(2)+4);

 con = present("wan", environment());
 inv = all_inventory(con);
   for(i=0; i<sizeof(inv); i++) {
                objname = (string)inv[i]->query("name");
                if( objname =="象牙骰子" && ((int)inv[i]->query_amount()>=3)) 
                 {
                  win=random(3);
                  if(!win) write("大管家喃喃的说：跟我耍老千，找死！\n");
                  }
                if( objname =="骰子") win=0;
                               
        }


if (baozi && win)
 {
 this_object()->set("forth_dice",5);
 this_object()->set("fifth_dice",5);
 this_object()->set("sixth_dice",5);
 }
else
 {
 this_object()->set("forth_dice",random(4));
 this_object()->set("fifth_dice",random(4));
 this_object()->set("sixth_dice",random(4));
 }
return;
}
