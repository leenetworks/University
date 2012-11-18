using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
public partial class carManage : System.Web.UI.Page
{
    
    public String posCol="";
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    public static System.Data.DataSet RunQuery(String QueryString)
    {
        SqlDataAdapter DBAdapter;
        DataSet ResultDataSet = new DataSet();
        String ConnectionString = "Data Source=.\\SQLEXPRESS;AttachDbFilename=E:\\car\\App_Data\\dbCar.mdf;Integrated Security=True;Connect Timeout=30;User Instance=True";
                                  
        SqlConnection DBConnection = new SqlConnection(ConnectionString);
        try
        {//建立DataSet
            DBAdapter = new SqlDataAdapter(QueryString, DBConnection);
        }
        catch (Exception ex)
        {
            throw new Exception(ex.Message);
        }
        finally
        {
            DBConnection.Close();
        }
        return ResultDataSet;
    }
   
    protected void Button1_Click(object sender, EventArgs e)
    {
        String num = TextBox1.Text;
        String sql = "select * from tb_carPos where carNum='" + num + "'";
        DataSet ds=RunQuery(sql);
        DataTable dt=ds.Tables[0];
        if (dt != null) {
            for (var m = 1; m <=10; m++) { 
                 posCol=","+dt.Rows[0]["x"+m]+"|"+dt.Rows[0]["y"+m];
             }
        
          }

    }
}