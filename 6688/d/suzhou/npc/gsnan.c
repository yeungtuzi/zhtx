//NPC:/d/suzhou/npc/gsnan.c 
//by dwolf   
//97.11.4
//changed by tlang
//97.12.4

#include <ansi.h>
inherit NPC;
mapping *step_phase;
mapping *read_table(string file);
int j;
string talk_me();

void create()
{
	set_name(YEL"左明珠"NOR, ({ "zuo mingzhu", "zuo"}) );
	set("gender", "女性" );
	set("age", 28);
        set("long",
		"她是一个可爱的女孩，不过她好象并不怎么温柔。\n");
	set("combat_exp", 50000);
	set("int",30);
	set("per",35);
	set("attitude", "heroism");
	set("rank_info/respect", "美女");
	set("pursuer", 1);    
	set("max_kee",1000);
	set("max_gin",500);
	set("max_sen",500);              
	set_skill("dodge",120);
	set_skill("chaos-steps",40);
	set_skill("blade",60);

	map_skill("dodge","chaos-steps");
	
	setup();
	add_money("gold",1);   
	carry_object("/d/hangzhou/npc/obj/sha.c")->wear(); 
	carry_object(__DIR__"obj/gangdao.c")->wield();
}

void init()
{
	remove_call_out("greeting");
	call_out("greeting",1,this_player()); 
	add_action("give_talk", "talk");
}

void greeting(object me)
{
	if( !me || environment(me) != environment() || 
!me->query("mark/开始") ) return;
	command("smile");
	command("say 有劳"+RANK_D->query_respect(me)+"了，请快些准备，
	到时给我说一声。\n");
}

int give_talk(string arg)
{
	object me;
	me=this_player();
	
	if(arg=="zuo" || arg=="zuo mingzhu")
	{
	if( !me->query("mark/开始") ) 
		return notify_fail("你要干什么？\n");
 	me->delete("mark/开始");
	me->set("test2",1);
	command("say 准备好了吗？我们走吧。\n");
	step_phase = read_table("/class/guard/step2");
        j=0; 
        remove_call_out("step");
	call_out("step", 5);
		return 1;
	} else {
		return notify_fail("你要和谁说话啊？\n");
	}
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]==	'#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]]);
		fn = (++fn) % sizeof(field);        
		if( !fn ) ++rn;
	}
	return data;
}


void step()
{
	object ob,obj;
	int i;        
	
	if (this_object()->is_fighting())
        {command("say 有人要杀我，你还不快来帮忙？!\n");
	//this_object()->start_busy(5);
        call_out("step", 1);
        return;
        }
        if (random(step_phase[j]["radom"])==1)             	
          {command("say 哎呀，这有坏人。\n");
	  // this_object()->start_busy(5);
	   ob=new("/d/suzhou/npc/mmren.c");
	   ob->move(step_phase[j]["where"]);
	   ob->kill_ob(this_object());
	   for(i=0; i<2; i++) {
		if( objectp( obj = present("tangzi shou " + (i+1), environment(this_object())) ) )
				 obj->kill_ob(ob);	
		else	this_object()->kill_ob(ob);		
	   }
           call_out("step", 1);
         return;
	  }
	command(step_phase[j]["command"]);
        j++;
        if (j==sizeof(step_phase))
	{command("say 任务完成了，你可以回去交差了。谢谢你，再见。\n");
	 this_player()->delete("test2");
	 this_player()->set("mark/成功", 1);
	 destruct(this_object());
	       	 return;
         }
	call_out("step", 1);
}

