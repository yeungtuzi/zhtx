#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int do_show_skills(string skillsfile,int line_no);

void create()
{
	set_name("造物主", ({ "master creater", "master","creater" }) );
	set("gender", "男性" );
	set("age", 99);
	set("int", 30);
        set("apprentice_available", 20);
        create_family("天堂", 20, "主持");
	set("long",
		"这就是万能的主。天地万物都是他的仁慈\n"
		);
	set("inquiry", ([
		"npc": "嗯....等一等。\n",
		"普松": "普松在大招寺的木屋里。",
	]) );
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 300);
        set_skill("staff", 400);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("literate", 150);
	set_skill("iron-cloth", 300);
	set_skill("magic", 150);

	set_skill("bloodystrike", 300);
	set_skill("cloudstaff", 300);
	set_skill("bolomiduo", 150);
	set_skill("buddhism", 300);
	set_skill("essencemagic", 300);
        set_skill("jin-gang", 300);


	map_skill("unarmed", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("force", "bolomiduo");
        map_skill("parry", "cloudstaff");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");
	setup();
}

void init() {

add_action("do_show_skills", "skill_query");
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本主持今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say 很好，很好，很好。");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
        add("apprentice_availavble", -1);
}

int do_show_skills(string skillsfile,int line_no) {

  string tmp_ppp;
  string skill_name,pakstring;
  int contiu;
  int i,num;
  mapping *action;

  if(!skillsfile )
      return notify_fail("请输入待处理skills文件名\n");
  notify_fail("Now begins to deal file:"+skillsfile + "....\n" );
  contiu = 1;
  printf("now processing No. %d\n",line_no);
write_file("/d/wizard/skillinfo","enter!\n",0);
  while(contiu ){
    if(tmp_ppp=read_file(skillsfile,line_no,1)){
      line_no++;
      if ( line_no % 10 == 0){
           contiu = 0;
           call_out( "do_show_skills",5,skillsfile,line_no);
      }
 //     printf("file:%s\n",tmp_ppp);
      if(!sizeof(tmp_ppp))
         break;
      sscanf(tmp_ppp,"%s\n",skill_name);
     // CHANNEL_D->do_channel(this_player(),"sys",skill_name);
      if( (skill_name)->query_action(this_object(),0) ) {
	tmp_ppp = sprintf("%s(",skill_name);
	write(tmp_ppp);
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
  	sscanf(skill_name,"/class/%s/skills/%s.c",tmp_ppp,pakstring);
	tmp_ppp = sprintf("%s):\n",to_chinese(pakstring));
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
	pakstring = "/d/wizard/skills/" + pakstring;
	printf("%s\n",pakstring);  	 	
	action = (pakstring)->query_all_action();
	num = sizeof(action);	
	tmp_ppp= sprintf("\tactions: %d\n\n",num);
	write(tmp_ppp);
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
      for ( i=0;i< num;i++) {
	tmp_ppp = sprintf("\t  %s\n",action[i]["action"]);
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
	tmp_ppp= sprintf("\t\tdamage:%d\n", action[i]["damage"]);
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
	tmp_ppp= sprintf("\t\tdodge:%d\n", action[i]["dodge"]);
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
	tmp_ppp= sprintf("\t\tparry:%d\n", action[i]["parry"]);
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
	tmp_ppp= sprintf("\t\tforce:%d\n\n", action[i]["force"]);
	write_file("/d/wizard/skillinfo",tmp_ppp,0);
	}
      }
     }
    else {
	printf("open error");
	break;
	}
    }
return(1);
}
