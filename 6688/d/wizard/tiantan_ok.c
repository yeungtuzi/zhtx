// /d/wizard/tiantan.c

#include <ansi.h>
#include <room.h>
#include <combat.h>

inherit ROOM;

int do_create_npc_query(string);
void create()
{
	set("short", "天堂");
	set("long", @LONG
这里是造物主的天堂，世界万物就是造物主在这里造出来的
LONG
	);

        set("objects", ([
                __DIR__"npc/creater":1 ]) );

	set("exits", ([
		"down": __DIR__"wizard_room",
		 ]));
	set("no_fight", "1");

	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_creat_npc_query", "npc_query");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "造物主抬头看了一眼，说道：这位" + RANK_D->query_respect(ob)
                                + "，最近有造了些什么垃圾？\n");
}

int do_creat_npc_query(string listfile,int line_no)
{
  object npc,me = this_player();
  object weapon,*inv;
  int i,contiu;
  string npc_name,fam_name;
  string npc_items,ob_items;
  string tmp_ppp;
  string attack_skill, skill_type,parry_type;
  int real_attacks,attack_points, dodge_points, parry_points;
  mapping prepare;


  mapping npcfam;

  if(!listfile )
      return notify_fail("请输入待处理NPC list文件名\n"); 
  notify_fail("Now begins to deal file:"+listfile + "....\n" );
  contiu = 1;
  while(contiu ){
    if(tmp_ppp=read_file(listfile,line_no,1)){
/*
      printf("read file No%d:%s,(%d)",line_no,tmp_ppp,sizeof(tmp_ppp));
*/
      printf("line_no:%d\n",line_no);
      line_no++;
      if ( line_no % 30 == 0){
           contiu = 0;
           call_out( "do_creat_npc_query",3,listfile,line_no);
      }
      if(!sizeof(tmp_ppp))
         continue;
      sscanf(tmp_ppp,"%s\n",npc_name);

//       CHANNEL_D->do_channel(this_player(),"sys",npc_name);

       npc=new(npc_name);
       if(!npc){
         printf("fail load file :%s\n " , npc_name);
         continue;
       }
       if(!npc->is_character()){
         printf("not npc\n");
         destruct(npc);
         continue;
       }
       else{ 

//	  CHANNEL_D->do_channel(me,"sys", npc->query("name"));
        write_file(listfile+".real",npc_name,0);
        write_file(listfile+".real","\n",0);
        
        prepare = npc->query_skill_prepare();
        if (!prepare) prepare = ([]);

        if ( sizeof(prepare) == 0) attack_skill = "unarmed";
          else if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
            else if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[npc->query_temp("action_flag")];

        if( objectp(weapon = npc->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
//         printf("attack_skill: %s\n",skill_type);
        }
        else
        {
                skill_type = attack_skill;
                parry_type = attack_skill;
//         printf("attack_skill:%s\n",attack_skill);
        }

        attack_points = COMBAT_D->skill_power(npc, skill_type, SKILL_USAGE_ATTACK
);
//        printf("attack_points:%d",attack_points);
        parry_points = COMBAT_D->skill_power(npc, parry_type, SKILL_USAGE_DEFENSE
);
//        printf("parry_points:%d",parry_points);
        dodge_points = COMBAT_D->skill_power(npc, "dodge", SKILL_USAGE_DEFENSE);
//        printf("dodge_points:%d\n",dodge_points);
         
          if(weapon)
             real_attacks =  parry_points/100 + 1;
          else
             real_attacks =  parry_points/200 + 1; 


//         printf(" npc:%s\n",npc->query("name"));
/* name, family, exp, shen, */
          npcfam = (mapping)npc->query("family");
          if(! npcfam)
               fam_name=0;
           else
               fam_name=npcfam["family_name"];
          npc_items=sprintf("%15s,%8d,%8d,%6d,%O\n",npc->query("name"),attack_points/100 + 1, real_attacks,npc->query("shen"),npc); 
          write_file(listfile+".kungfu",npc_items,0);

         inv = all_inventory(npc);
         if( !sizeof(inv) ){
             notify_fail(npc->query("name")+" doesnt has any inventory\n");
             continue;
          }
/*         CHANNEL_D->do_channel(me,"sys",npc->query("name")+" has "+ sizeof(inv) +"个物品");
  */
//        printf("%s 有 %d 个物品\n",npc->query("name"),sizeof(inv));
        for(i=0;i<sizeof(inv);i++){
            ob_items=sprintf("%s,%10d,%10d,%O\n",inv[i]->query("name"),inv[i]->query("value"),real_attacks,inv[i]);
            notify_fail(ob_items);
            write_file(listfile+".obj",ob_items,0);
         }

          destruct(npc);
        } 
    }
    else{
       printf("end of file,line= %d\n",line_no);
       break;
    }
  }
return(1);
}

void inventory_deal(object ob , string queryfile,object owner)
{
   string ob_items;
/* name, owner's exp, owner's family */
   ob_items=sprintf("%s,%s,%s\n",ob->query("name"),owner->query("combat_exp"),owner->query("family"));
   notify_fail(ob_items);
   write_file(queryfile,ob_items,0);
} 
   
