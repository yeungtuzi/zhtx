//by tlang
//97.12
//duan3.c

#include <ansi.h>
inherit NPC;

void step();
mapping *step_phase;
mapping *read_table(string file);
int j;

void create()
{
	set_name(HIM"段玉"NOR, ({"duan yu", "duan"}) );
	set("long", "他穿着鲜明的绸衫，很轻，很薄，剪裁得很合身，脚上穿着\n"
"特地从关外买来的小牛皮软马靴，手上拿着温州“皮硝李”精制的乌梢马鞭，把手\n"
"上还镶着颗比龙眼还大三分的明珠。\n");
	set("per", 30);
	set("int", 40);
	set("str", 30);
	set("gender", "男性");
	set("age", 19);
	set("combat_exp", 500000);
	
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("parry", 100);
	set_skill("blade", 100); 
	set_skill("force", 100);
	set_skill("jingang-quan", 100);
	set_skill("hunyuan-yiqi", 100);
	//set_skill("cibei-dao", 100);
	set_skill("xiaoyaoyou", 100);
	//map_skill("blade", "cibei-dao");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff", "jingang-quan");

	add_money("gold", 2);
	setup();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
}

void init()
{
    ::init();
    remove_call_out("greeting");
    call_out("greeting",5,this_player());
}

void greeting()
{
	object me;
	me=this_player();

	if( !me->query("mark/goon") ) 
		return;
 	command("say 哪里走？\n");
	step_phase = read_table("/d/hangzhou/step3");
        j=0; 
        remove_call_out("step");
	call_out("step", 3);
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
	// 2026-04-30: unused variable commented out
	// object ob;
	int i;        
	
	if (this_object()->is_fighting())
        {command("say 闪开，别找麻烦!\n");
	this_object()->start_busy(1);
        call_out("step", 1);
        return;
        }
        if (random(step_phase[j]["radom"])==1)             	
          {command("sigh\n");
	   this_object()->start_busy(1);
	   call_out("step", 1);
         return;
	  }
	if(stringp(step_phase[j]["command"]))
	command(step_phase[j]["command"]);
        j++;
        if (j==sizeof(step_phase))
	{command("say 肯定在庙里去了。\n");
	 destruct(this_object());
	       	 return;
         }
	call_out("step", 1);
}

