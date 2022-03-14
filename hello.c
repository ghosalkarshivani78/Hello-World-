 protected void city_SelectedIndexChanged(object sender, EventArgs e)
        {
            string strcon = ConfigurationManager.ConnectionStrings["taskformEntities"].ConnectionString;
            MySqlConnection con = new MySqlConnection(strcon);
            string sql = "SELECT * FROM task t LEFT JOIN city_fk c ON t.cityid = c.cityid;";
            con.Open();
            MySqlCommand cmd = new MySqlCommand(sql, con);
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            DataSet dt = new DataSet();
            da.Fill(dt);
            city.DataSource = dt;
            city.DataTextField = dt.Tables[0].Columns["city_fk"].ToString();
            city.DataValueField = dt.Tables[0].Columns["cityid"].ToString();
            city.DataSource = dt.Tables[0];  
            city.DataBind();
            //city.Items.Insert(0, new ListItem("--Select--", "0"));
            
            //MySqlDataReader sdr = cmd.ExecuteReader();
            //while (sdr.Read())
            //{
            //    Console.Write(sdr["firstname"].ToString() + ", ");
            //    Console.Write(sdr["lastname"].ToString() + ", ");
            //    Console.Write(sdr["email"].ToString() + ", ");
            //    Console.WriteLine(sdr["address"].ToString() + ", ");
            //    Console.Write(sdr["city_fk"].ToString() + ", ");
            //    Console.WriteLine(sdr["number"].ToString() + ", ");
            //}
           
        }


