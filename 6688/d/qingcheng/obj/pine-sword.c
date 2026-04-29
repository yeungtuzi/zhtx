inherit ITEM;

void create()
{
        set_name("松风剑谱" , ({ "pine-sword" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是青城祖传的松风剑谱.\n");
        set("skill", ([
                "name":                 "pine-sword",      
                "exp_required": 30000,       
                    "sen_coust":30,
                "difficulty":   30,  
                    "base_skill" :   30,
                "max_skill":    100     
        ]) );
}
      
